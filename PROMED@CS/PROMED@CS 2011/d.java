import java.util.*;
import java.math.*;

public class d
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        for(int z = 1, n; ; z++)
        {
            n = in.nextInt();

            for(int i = 1; ;i++)
            {
                String sequence = new String();
                for(int b = 0; b < i; b++) sequence += "7";

                BigInteger sum = new BigInteger(sequence), divisor = new BigInteger("" + n);

                sum = sum.remainder(divisor);

                if(sum.compareTo((new BigInteger("" + 0))) == 0)
                {
                    System.out.println("Case " + z + " : " + sequence.length());
                    break;
                }
            }
        }
    }
}
