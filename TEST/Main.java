import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        int input = 0;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while ((s = in.readLine()) != null && s.length() != 0) {
            input = Integer.parseInt(s);
            if (42 == input)
                return;
            System.out.println(input);
        }
    }
}
