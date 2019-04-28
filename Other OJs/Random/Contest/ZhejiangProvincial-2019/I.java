import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        new Solver().solve(new Reader(System.in));
    }
}

class Solver {
    private static final BigInteger THREE = new BigInteger("3");

    public void solve(Reader in) {
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            BigInteger a = new BigInteger(in.next());
            BigInteger b = new BigInteger(in.next());

            a = a.subtract(BigInteger.ONE);

            boolean pre = a.divideAndRemainder(THREE)[1].equals(BigInteger.ONE);
            boolean lat = b.divideAndRemainder(THREE)[1].equals(BigInteger.ONE);

            if(pre == lat)
                System.out.println(0);
            else
                System.out.println(1);
        }
    }
}

class Reader {
    BufferedReader br;
    StringTokenizer st;

    public Reader(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in), 1 << 22);
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public boolean hasNext() {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null)
                return false;
            eat(s);
        }
        return true;
    }

    public String next() {
        hasNext();
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}

// 大数问题选择