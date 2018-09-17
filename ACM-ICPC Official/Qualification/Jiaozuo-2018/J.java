import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        new Solver().solve();
    }
}

class Solver {
    private final BigInteger two = new BigInteger("2");

    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1 << 16);

        int T = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
        for (int kase = 0; kase < T; kase++) {
            BigInteger n = new BigInteger(new StringTokenizer(br.readLine()).nextToken());
            BigInteger m = n.multiply(n.subtract(BigInteger.ONE)).divide(new BigInteger("2"));
            BigInteger ns = sqrt(n.toString()), ms = sqrt(m.toString());
            boolean f1 = n.equals(ns.multiply(ns)), f2 = m.equals(ms.multiply(ms));
            if (f1 && f2) {
                System.out.println("Arena of Valor");
            } else if (!f1 && f2) {
                System.out.println("Clash Royale");
            } else if (f1 && !f2) {
                System.out.println("Hearth Stone");
            } else {
                System.out.println("League of Legends");
            }

        }
    }

    public BigInteger sqrt(String x) {
        BigInteger t = new BigInteger(x);
        BigInteger ret;

        if ((x.length() & 1) == 1) {
            ret = new BigInteger(x.substring(0, x.length() / 2 + 1));
        } else {
            ret = new BigInteger(x.substring(0, (1 + x.length() / 2) + 1));
        }

        if (t.equals(BigInteger.ONE))
            return BigInteger.ONE;

        while (t.compareTo(ret.multiply(ret)) < 0)
            ret = ret.add(t.divide(ret)).divide(two);

        return ret;
    }
}