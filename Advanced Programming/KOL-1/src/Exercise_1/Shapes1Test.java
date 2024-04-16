package Exercise_1;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Canvas{
    private String id;
    private List<Integer> squares;

    public Canvas(String id, List<Integer> squares) {
        this.id = id;
        this.squares = squares;
    }

    public int getNumOfSquares(){
        return squares.size();
    }

    public int getPerimeter(){
        return squares.stream()
                .mapToInt(s -> s+s+s+s)
                .sum();
    }

    @Override
    public String toString() {
        return String.format("%s %d %d", id, getNumOfSquares(), getPerimeter());
    }
}

class CanvasFactory{
    public static Canvas createCanvas(String line){
        String[] lines = line.split("\\s+");

        String id = lines[0];

        List<Integer> squares = new ArrayList<>();

        for(int i = 1; i < lines.length; i++){
            squares.add(Integer.parseInt(lines[i]));
        }

        return new Canvas(id, squares);
    }
}
class ShapesApplication{
    private List<Canvas> canvases;

    public ShapesApplication() {
        this.canvases = new ArrayList<>();
    }

    public int readCanvases(InputStream in) {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));

        canvases = br
                .lines()
                .map(CanvasFactory::createCanvas)
                .collect(Collectors.toList());

        return canvases.stream()
                .mapToInt(Canvas::getNumOfSquares)
                .sum();
    }

    public void printLargestCanvasTo(PrintStream out) {
        PrintWriter pw = new PrintWriter(out, true);

        pw.println(canvases.stream()
                .sorted(Comparator.comparing(Canvas::getPerimeter).reversed())
                .findFirst()
                .orElse(null));
    }
}

public class Shapes1Test {

    public static void main(String[] args) {
        ShapesApplication shapesApplication = new ShapesApplication();

        System.out.println("===READING SQUARES FROM INPUT STREAM===");
        System.out.println(shapesApplication.readCanvases(System.in));
        System.out.println("===PRINTING LARGEST CANVAS TO OUTPUT STREAM===");
        shapesApplication.printLargestCanvasTo(System.out);

    }
}
