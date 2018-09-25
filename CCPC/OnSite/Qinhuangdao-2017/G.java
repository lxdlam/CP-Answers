import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        new Solver().solve(new Reader(System.in));
    }
}

class Solver {
    public void solve(Reader in) {

        int T = in.nextInt();
        for (int kase = 0; kase < T; kase++) {
            BigInteger n = new BigInteger(in.next());
            BigInteger m = new BigInteger(in.next());
            BigInteger ans = BigInteger.ZERO;
            while (true) {
                BigInteger[] ret = n.divideAndRemainder(m);

                if (ret[1].equals(BigInteger.ZERO)) {
                    System.out.println(ans.add(ret[0]));
                    break;
                }
            }
        }
    }
}

class Reader {
    BufferedReader br;
    StringTokenizer st;

    public Reader(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in), 16384);
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