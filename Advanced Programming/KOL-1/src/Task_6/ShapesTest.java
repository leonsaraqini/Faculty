package Task_6;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

enum Color {
    RED, GREEN, BLUE
}

interface Scalable{
    void scale(double scaleFactor);
}

interface Stackable{
    float weight();
}


abstract class Shape implements Scalable,Stackable{
    private String id;
    private Color color;

    public Shape(String id, Color color) {
        this.id = id;
        this.color = color;
    }
    abstract String typeOfShape();

    public String color(){
        switch (color){
            case RED:
                return "RED";
            case BLUE:
                return "BLUE";
            default:
                return "GREEN";
        }
    }

    public String getId() {
        return id;
    }

    @Override
    public String toString() {
        return String.format("%s: %-5s%-10s%10.2f", typeOfShape(), id, color(), weight());
    }
}

class Rectangle extends Shape{
    private float width;
    private float height;

    public Rectangle(String id, Color color, float width, float height) {
        super(id, color);
        this.width = width;
        this.height = height;
    }

    @Override
    public float weight() {
        return width * height;
    }

    @Override
    String typeOfShape() {
        return "R";
    }

    @Override
    public void scale(double scaleFactor) {
        width *= scaleFactor;
        height *= scaleFactor;
    }
}

class Circle extends Shape{
    private float radius;

    public Circle(String id, Color color, float radius) {
        super(id, color);
        this.radius = radius;
    }

    @Override
    public float weight() {
        return (float) Math.PI * radius * radius;
    }

    @Override
    String typeOfShape() {
        return "C";
    }

    @Override
    public void scale(double scaleFactor) {
        radius *= scaleFactor;
    }
}

class Canvas{
    List<Shape> shapes;

    public Canvas() {
        this.shapes = new ArrayList<>();
    }


    public void add(String id, Color color, float radius) {
        shapes.add(new Circle(id, color, radius));
    }

    public void add(String id, Color color,float width, float height){
        shapes.add(new Rectangle(id, color, width, height));
    }


    public void scale(String id, float scaleFactor) {
        Shape s = shapes.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .get();

        s.scale(scaleFactor);
    }

    @Override
    public String toString() {
        shapes = shapes.stream()
                .sorted(Comparator
                        .comparing(Stackable::weight)
                        .reversed())
                .collect(Collectors.toList());

        StringBuilder sb = new StringBuilder();

        shapes.forEach(s -> sb.append(s.toString() + "\n"));

        return sb.toString();
    }
}


public class ShapesTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Canvas canvas = new Canvas();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            int type = Integer.parseInt(parts[0]);
            String id = parts[1];
            if (type == 1) {
                Color color = Color.valueOf(parts[2]);
                float radius = Float.parseFloat(parts[3]);
                canvas.add(id, color, radius);
            } else if (type == 2) {
                Color color = Color.valueOf(parts[2]);
                float width = Float.parseFloat(parts[3]);
                float height = Float.parseFloat(parts[4]);
                canvas.add(id, color, width, height);
            } else if (type == 3) {
                float scaleFactor = Float.parseFloat(parts[2]);
                System.out.println("ORIGNAL:");
                System.out.print(canvas);
                canvas.scale(id, scaleFactor);
                System.out.printf("AFTER SCALING: %s %.2f\n", id, scaleFactor);
                System.out.print(canvas);
            }

        }
    }
}