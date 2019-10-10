/* Author:Shaun Lee
 * April 30,019
 * Version 1
 * Class Overview:Test out the functions of a simulated multi inheritance using interfaces
 * 
 * Functions: FlipTest();
              pwdCheckRequestTest();
              FlippwdCheckGen();
              compundCRequestTest();
 * 
 * //Class Implementation: It is the client's responsibility to get desired results due to randomness in this testing

 */
using System;
using System.Linq;

class P6
{

    public static void Main(string[] args)
    {
        FlipTest();
        pwdCheckRequestTest();
        compundCRequestTest();
        excessCFunctionTest();
    }

    //PRE:NONE
    //POST:FlippwdCheck array is returned with random strings and randomly set p value

    private static FlippwdCheck[] FlippwdCheckGen()
    {
        const int RANDLOW = 2;
        const int RANDHIGH = 10;
        const int SIZE = 10;
        const int STRSIZE = 12;
        Random rand = new Random();
        int pvalue;
        string randomstr;
        FlippwdCheck[] array = new FlippwdCheck[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            randomstr = RandomString(STRSIZE);
            pvalue = rand.Next(RANDLOW, RANDHIGH);
            Console.WriteLine(i + ":pvalue:" + pvalue + "\tpassword:" + randomstr);
            array[i] = new FlippwdCheck(rand.Next(RANDLOW,RANDHIGH));
            array[i].changepw(randomstr);

        }
        Console.WriteLine();
        return array;
    }

    //PRE:NONE
    //POST:Prints out result of FlipTest()

    public static void FlipTest()
    {
        Console.WriteLine("\n\t----- FlipTest() -----");
        const int SIZE = 10;
        const int LOW = 1;
        const int MAX = 12;
        Random rand = new Random();
        int randint;
        FlippwdCheck[] arr = FlippwdCheckGen();
        for (int i = 0; i < SIZE; i++)
        {
            randint = rand.Next(LOW,MAX);
            Console.WriteLine(i + ": FlipNum:" + randint + "\tFlipString:" + arr[i].flipFunc(randint));
        }
    }

    //PRE:NONE
    //POST:Prints out result of pwdCheckRequestTest()

    public static void pwdCheckRequestTest()
    {
        Console.WriteLine("\n\t----- pwdCheckRequestTest() -----");
        const int SIZE = 10;
        FlippwdCheck[] arr = FlippwdCheckGen();
        for (int i = 0; i < SIZE; i++)
        {
            Console.WriteLine(i + ":" + arr[i].pwdCheckrequest());
        }
    }

    //PRE:NONE
    //POST:Prints out result of compundCRequestTest()

    public static void compundCRequestTest()
    {
        Console.WriteLine("\n\t----- compundCRequestTest -----");
        Console.WriteLine("\nDEFAULT K VALUE IS 2\n");
        const int SIZE = 10;
        FlippwdCheck[] arr = FlippwdCheckGen();
        for (int i = 0; i < SIZE; i++)
        {
            Console.WriteLine(i + ":" + arr[i].compundCrequest());
        }
    }

    //PRE:NONE
    //POST:Prints out result of excessCFunctionTest()

    public static void excessCFunctionTest()
    {
        Console.WriteLine("\t----- excessCRequestTest() -----");
        Console.WriteLine("\n REQUIREMENTS: pth char has to be a digit,upper and lower case, and has a '$'\n");

        const int SIZE = 10;
        FlippwdCheck[] arr = FlippwdCheckGen();
        for (int i = 0; i < SIZE; i++)
        {
            Console.WriteLine(i + ":" + arr[i].excessCrequest());
        }
    }

    //PRE:input an integer
    //POST:returns a random string with possiblity of the chars in the chars string with the length of the integer in the param

    public static string RandomString(int length)
    {
        const string chars = "♠♣♥♦abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$";
        return new string(Enumerable.Repeat(chars, length)
          .Select(s => s[random.Next(s.Length)]).ToArray());
    }
    private static Random random = new Random();
}

