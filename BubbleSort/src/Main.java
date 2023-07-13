import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(5);
        numbers.add(1);
        numbers.add(3);
        numbers.add(2);
        numbers.add(4);
        numbers.add(7);
        numbers.add(6);

        int size = numbers.size() - 1;

        for (int i = 0; i < size; i++) {
            int j = i + 1;

            Integer x = numbers.get(i);
            Integer y = numbers.get(j);

            if (x > y) {
                numbers.set(i, y);
                numbers.set(j, x);
            }
        }

        for (Integer num : numbers) {
            System.out.println(num);
        }
    }

}
