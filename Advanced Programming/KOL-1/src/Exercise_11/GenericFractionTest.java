package Exercise_11;

import java.util.Scanner;

class GenericFraction<T extends Number,U extends Number>{
    private T numerator;
    private U denominator;

    public GenericFraction(T numerator, U denominator) throws ZeroDenominatorException {
        if(denominator.intValue() == 0)
            throw new ZeroDenominatorException();

        this.numerator = numerator;
        this.denominator = denominator;
    }

    public GenericFraction<Double, Double> add(GenericFraction<? extends Number, ? extends Number> gf) throws ZeroDenominatorException {
        double denominator = leastCommonMultiple(getDenominator(), gf.getDenominator());

        double numerator = ((denominator/ getDenominator()) * getNumerator()) + ((denominator / gf.getDenominator()) * gf.getNumerator());

        for(int i = 2; i <= numerator && i <= denominator; i++){
            if(numerator % i == 0 && denominator % i == 0){
                numerator /= i;
                denominator /= i;
                i=1;
            }
        }

        return new GenericFraction<>(numerator,denominator);
    }

    public double leastCommonMultiple(double a, double b){
        int gcd = 1;

        for(int i = 1; i <= a && i <= b; i++){
            if(a % i == 0 && b % i == 0)
                gcd = i;
        }

        return (a * b) / gcd;
    }

    public double toDouble(){
        return numerator.doubleValue() / denominator.doubleValue();
    }

    public double getNumerator() {
        return numerator.doubleValue();
    }

    public double getDenominator() {
        return denominator.doubleValue();
    }

    @Override
    public String toString() {
        return String.format("%.2f / %.2f", getNumerator(), getDenominator());
    }
}


class ZeroDenominatorException extends Exception{
    public ZeroDenominatorException() {
        super("Denominator cannot be zero");
    }
}


public class GenericFractionTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double n1 = scanner.nextDouble();
        double d1 = scanner.nextDouble();
        float n2 = scanner.nextFloat();
        float d2 = scanner.nextFloat();
        int n3 = scanner.nextInt();
        int d3 = scanner.nextInt();
        try {
            GenericFraction<Double, Double> gfDouble = new GenericFraction<Double, Double>(n1, d1);
            GenericFraction<Float, Float> gfFloat = new GenericFraction<Float, Float>(n2, d2);
            GenericFraction<Integer, Integer> gfInt = new GenericFraction<Integer, Integer>(n3, d3);
            System.out.printf("%.2f\n", gfDouble.toDouble());
            System.out.println(gfDouble.add(gfFloat));
            System.out.println(gfInt.add(gfFloat));
            System.out.println(gfDouble.add(gfInt));
            gfInt = new GenericFraction<Integer, Integer>(n3, 0);
        } catch(ZeroDenominatorException e) {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }

}

// вашиот код овде

