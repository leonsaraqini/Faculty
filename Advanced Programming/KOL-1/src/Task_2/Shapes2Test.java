package Task_2;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

abstract class Shape {
    private double size;

    public Shape(double size) {
        this.size = size;
    }

    public double getSize() {
        return size;
    }

    abstract String typeOfShape();

    abstract double areaOfShape();
}

class Square extends Shape {

    public Square(double size) {
        super(size);
    }

    @Override
    double areaOfShape() {
        return getSize() * getSize();
    }

    @Override
    String typeOfShape() {
        return "S";
    }
}

class Circle extends Shape {

    public Circle(double size) {
        super(size);
    }

    @Override
    String typeOfShape() {
        return "C";
    }

    @Override
    double areaOfShape() {
        return Math.PI * getSize() * getSize();
    }
}

class Canvas{
    private String id;
    private List<Shape> shapes;

    public Canvas(String id, List<Shape> shapes) {
        this.id = id;
        this.shapes = shapes;
    }

    public double sumOfAreas(){
        return shapes.stream()
                .mapToDouble(Shape::areaOfShape)
                .sum();
    }

    public double getMaxArea(){
        return shapes.stream()
                .mapToDouble(Shape::areaOfShape)
                .max()
                .orElse(0);
    }

    public double getMinArea(){
        return shapes.stream()
                .mapToDouble(Shape::areaOfShape)
                .min()
                .orElse(0);
    }

    public double getAverageArea(){
        return shapes.stream()
                .mapToDouble(Shape::areaOfShape)
                .average()
                .orElse(0);
    }

    public int getCountOfSquares(){
        return (int) shapes.stream()
                .filter(s -> s.typeOfShape().equals("S"))
                .count();
    }

    public int getCountOfCircles(){
        return (int) shapes.stream()
                .filter(s -> s.typeOfShape().equals("C"))
                .count();
    }

    public int getCountOfShapes(){
        return shapes.size();
    }

    @Override
    public String toString() {
        return String.format("%s %d %d %d %.2f %.2f %.2f",
                id, getCountOfShapes(), getCountOfCircles(), getCountOfSquares(),
                getMinArea(), getMaxArea(), getAverageArea());
    }
}

class CanvasFactory{
    public static Canvas createCanvas(String line, int maxAllowedArea) throws InvalidCanvasException {
        String[] parts = line.split("\\s+");
        String id = parts[0];

        List<Shape> shapes = new ArrayList<>();

        for(int i = 1; i < parts.length - 1; i += 2){
            Shape s;

            if(parts[i].equals("S")){
                s = new Square(Double.parseDouble(parts[i+1]));
            }else{
                s = new Circle(Double.parseDouble(parts[i+1]));
            }

            if(s.areaOfShape() > maxAllowedArea)
                throw new InvalidCanvasException(id, maxAllowedArea);

            shapes.add(s);
        }
        return new Canvas(id, shapes);
    }
}

class ShapesApplication{
    private List<Canvas> canvases;
    private int maxAllowedArea;

    public ShapesApplication(int maxAllowedArea){
        canvases = new ArrayList<>();
        this.maxAllowedArea = maxAllowedArea;
    }


    public void readCanvases(InputStream in) {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));

        canvases = br.lines()
                .map(s -> {
                    try {
                        return CanvasFactory.createCanvas(s, maxAllowedArea);
                    } catch (InvalidCanvasException e) {
                        System.out.println(e.getMessage());
                    }
                    return null;

                })
                .filter(Objects::nonNull)
                .collect(Collectors.toList());

        canvases = canvases.stream()
                .sorted(Comparator
                        .comparing(Canvas::sumOfAreas)
                        .reversed())
                .collect(Collectors.toList());
    }

    public void printCanvases(PrintStream out) {
        PrintWriter pw = new PrintWriter(out, true);

        canvases.forEach(pw::println);
    }
}

class InvalidCanvasException extends Exception {
    public InvalidCanvasException(String id, double maxAllowedArea) {
        super(String.format("Canvas %s has a shape with area larger than %.2f", id, maxAllowedArea));
    }
}

public class Shapes2Test {

    public static void main(String[] args) {

        ShapesApplication shapesApplication = new ShapesApplication(10000);

        System.out.println("===READING CANVASES AND SHAPES FROM INPUT STREAM===");
        shapesApplication.readCanvases(System.in);

        System.out.println("===PRINTING SORTED CANVASES TO OUTPUT STREAM===");
        shapesApplication.printCanvases(System.out);


    }
}