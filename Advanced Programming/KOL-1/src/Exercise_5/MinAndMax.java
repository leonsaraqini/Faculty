package Exercise_5;

import java.util.Comparator;
import java.util.Scanner;

class MinMax<T extends Comparable<T>>{
    private T min;
    private T max;
    private int count;
    private int minCount;
    private int maxCount;

    public MinMax() {
        count =  0;
        minCount = maxCount = 1;
    }


    public void update(T s) {
        if(min == null && max == null){
            min = max = s;
            count++;
            return;
        }

        if(min.compareTo(s) == 0){
            minCount++;
        }

        if(min.compareTo(s) > 0){
            min = s;
            minCount = 1;
        }

        if(max.compareTo(s) == 0){
            maxCount++;
        }

        if(max.compareTo(s) < 0){
            max = s;
            maxCount = 1;
        }
        count++;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d\n", min, max, count - minCount - maxCount);
    }
}

public class MinAndMax {
    public static void main(String[] args) throws ClassNotFoundException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        MinMax<String> strings = new MinMax<String>();
        for(int i = 0; i < n; ++i) {
            String s = scanner.next();
            strings.update(s);
        }
        System.out.println(strings);
        MinMax<Integer> ints = new MinMax<Integer>();
        for(int i = 0; i < n; ++i) {
            int x = scanner.nextInt();
            ints.update(x);
        }
        System.out.println(ints);
    }
}