import java.util.Scanner;
import java.math.BigInteger;

public class BigIntTemplate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a, b;
        while (sc.hasNext()) {
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            System.out.println(a.add(b.negate()).abs());
            // operations:
            // a.add(b); => a+b
            // a.add(b.negate()); => a-b;
            // a.abs() => |a|
            // a.gcd(b) => gcd(a,b)
            // TODO: add more ops
        }
        sc.close();
    }
}