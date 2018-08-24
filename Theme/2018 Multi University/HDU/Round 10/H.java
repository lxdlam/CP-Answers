import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {
        new Solver().solve();
    }
}

class Solver {
    BigInteger TWO = BigInteger.valueOf(2);

    BigInteger fast_pow(BigInteger base, BigInteger expr) {
        BigInteger ans = BigInteger.ONE;
        while (!expr.equals(BigInteger.ZERO)) {
            if (expr.mod(TWO).equals(BigInteger.ONE))
                ans = ans.multiply(base);
            base = base.multiply(base);
            expr = expr.divide(TWO);
        }
        return ans;
    }

    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            BigInteger b = BigInteger.valueOf(Integer.parseInt(br.readLine()));
            System.out.println(fast_pow(TWO, b));
        }
    }
}