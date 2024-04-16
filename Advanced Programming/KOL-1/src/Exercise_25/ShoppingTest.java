package Exercise_25;

import java.io.OutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

abstract class Product{
    private int Id;
    private String name;
    private float price;
    private float quantity;

    public Product(int id, String name, float price, float quantity) {
        Id = id;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public int getId() {
        return Id;
    }

    public String getName() {
        return name;
    }

    public float getPrice() {
        return price;
    }

    public float getQuantity() {
        return quantity;
    }

    public void setPrice() {
        this.price = (float) (price / 10.00);
    }

    public abstract float getTotalPrice();

    @Override
    public String toString() {
        return String.format("%d - %.2f", Id, getTotalPrice());
    }
}

class FullProduct extends Product{
    public FullProduct(int id, String name, int price, float quantity) {
        super(id, name, price, quantity);
    }

    @Override
    public float getTotalPrice() {
        return getPrice() * getQuantity();
    }
}

class WeightProduct extends Product{
    public WeightProduct(int id, String name, int price, float quantity) {
        super(id, name, price, quantity);
    }

    @Override
    public float getTotalPrice() {
        return (float) ((0.001 * getQuantity()) * getPrice());
    }
}

class ShoppingCart{
    private List<Product> products;

    public ShoppingCart() {
        products = new ArrayList<>();
    }


    public void addItem(String itemData) throws InvalidOperationException {
        String[] lines = itemData.split(";");

        String type = lines[0];
        int id = Integer.parseInt(lines[1]);
        String name = lines[2];
        int price = Integer.parseInt(lines[3]);
        float quantity = Float.parseFloat(lines[4]);

        if(quantity == 0){
            throw new InvalidOperationException(String.format("The quantity of the product with id %d can not be 0.", id));
        }

        if(type.equals("PS")){
            products.add(new WeightProduct(id, name, price, quantity));
        }else{
            products.add(new FullProduct(id, name, price, quantity));
        }
    }


    public void printShoppingCart(OutputStream os) {
        PrintWriter writer = new PrintWriter(os, true);

        products = products.stream()
                .sorted(Comparator
                        .comparing(Product::getTotalPrice)
                        .reversed())
                .collect(Collectors.toList());

        products.forEach(writer::println);
    }

    void blackFridayOffer(List<Integer> discountItems, OutputStream os) throws InvalidOperationException {
        if(discountItems.isEmpty()){
            throw new InvalidOperationException("There are no products with discount.");
        }

        PrintWriter pw = new PrintWriter(os, true);


        products.stream()
                .filter(p -> discountItems.contains(p.getId()))
                .forEachOrdered(Product::setPrice);


        products.stream()
                .filter(p -> discountItems.contains(p.getId()))
                .forEach(pw::println);

    }


}

class InvalidOperationException extends Exception{
    public InvalidOperationException(String message) {
        super(message);
    }
}

public class ShoppingTest {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ShoppingCart cart = new ShoppingCart();

        int items = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < items; i++) {
            try {
                cart.addItem(sc.nextLine());
            } catch (InvalidOperationException e) {
                System.out.println(e.getMessage());
            }
        }

        List<Integer> discountItems = new ArrayList<>();
        int discountItemsCount = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < discountItemsCount; i++) {
            discountItems.add(Integer.parseInt(sc.nextLine()));
        }

        int testCase = Integer.parseInt(sc.nextLine());
        if (testCase == 1) {
            cart.printShoppingCart(System.out);
        } else if (testCase == 2) {
            try {
                cart.blackFridayOffer(discountItems, System.out);
            } catch (InvalidOperationException e) {
                System.out.println(e.getMessage());
            }
       } else {
            System.out.println("Invalid test case");
        }
    }
}