import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main{
    public static void main(String[] args){
        new Solver().solve(new Reader(System.in));
    }
}

class Solver{
    public void solve(Reader in) {
        // codes
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