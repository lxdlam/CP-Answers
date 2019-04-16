import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        new Solver().solve(new Reader(System.in));
    }
}

class Solver {
    private static final SimpleDateFormat FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    public void solve(Reader in) {
        try {
            final Date DATE = FORMAT.parse("2050-01-01 00:00:00");
            int T = in.nextInt();
            for (int i = 0; i < T; i++) {
                String s = in.nextLine();
                Date date = FORMAT.parse(s);
                System.out.println(((DATE.getTime() - date.getTime()) / 1000) % 100);
            }
        } catch (Exception e) {

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