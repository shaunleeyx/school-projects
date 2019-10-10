/* Author:Shaun Lee
 * April 30,019
 * Version 1
 * Class Overview:Test out the functions of compundC,excessC, and pwdCheck
 * 
 * Functions: pwdCheckFunctionTest();
            excessCFunctionTest();
            compundCFunctionTest();
 *          RandomString();
 *          forbiddenRandomString();
 *          RandomStringrepeat();
 */
using System;
using System.Linq;

class P3
{

    public static void Main(string[] args)
    {


 
        pwdCheckFunctionTest();
        excessCFunctionTest();
        compundCFunctionTest();


    }


    public static void pwdCheckFunctionTest()
    {
        string strtemp;
        int inttemp;
        Random rand = new Random();
        Console.WriteLine("----- pwdCheckFunctionTest() -----");
        Console.WriteLine("\nTesting if active switches automatically inputting random string with no illegal characters");
        inttemp = rand.Next(2, 4);
        pwdCheck obj = new pwdCheck(inttemp);
        Console.WriteLine("p:" + inttemp + " active:" + obj.getActive());
        for(int i = 0; i < 10; i++)
        {
            strtemp = RandomString(rand.Next(2, 10));
            Console.WriteLine("string:" + strtemp + " active:" + obj.getActive());
            obj.request(strtemp);
        }
        Console.WriteLine("\nTesting if it doesn't accept illegal characters. illegal chars: ⇔£¥€©®™†‡§¶°…–—±×÷¼⅓½⅔¾μπ←↑→↓↔↵⇐⇒⇓⇔♠♣♥♦");
        for (int i = 0; i < 10; i++)
        {
            strtemp = forbiddenRandomString(rand.Next(2, 10));
            Console.Write("string:" + strtemp + " request's return:");
            Console.WriteLine(obj.request(strtemp));
        }
        Console.WriteLine("\nTesting if return false if length of pw is lower than p input string is 'a' and p is " + inttemp);
        Console.WriteLine(obj.request("a"));

    }

    public static void compundCFunctionTest()
    {
        int inttemp;
        int inttemp1;
        //i made it a static string b/c you wouldn't want to rng a repeating character string
        const string teststring = "Helloworld";
        Random rand = new Random();
        Console.WriteLine("\n----- compundCFunctionTest() -----");
        Console.WriteLine("\nTesting if returns true if repeating characters and stops if it cycles is above  k. ");
        inttemp = rand.Next(2, 4);
        inttemp1 = rand.Next(2, 4);
        compundC obj = new compundC(inttemp, inttemp1);
        Console.WriteLine("p:" + inttemp + "\tk:" + inttemp1);
        for (int i = 0; i < 30; i++)
        {
            Console.WriteLine(obj.request(teststring));
        }
    }
    public static void excessCFunctionTest()
    {
        string strtemp;
        int inttemp;
        Random rand = new Random();
        Console.WriteLine("----- excessCFunctionTest() -----");
        Console.WriteLine("\nTesting if it returns true when mixed cases with $ and if the number at p is a digit");
        inttemp = rand.Next(2, 4);
        excessC obj = new excessC(inttemp);
        for (int i = 0; i < 40; i++)
        {
            strtemp = RandomStringrepeat(rand.Next(5,10));
            Console.WriteLine(strtemp + " excessC return:" + obj.request(strtemp) + "   p:" + inttemp);
        }

    }


    public static string RandomString(int length)
    {
        const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$";
        return new string(Enumerable.Repeat(chars, length)
          .Select(s => s[random.Next(s.Length)]).ToArray());
    }
    public static string RandomStringrepeat(int length)
    {
        const string chars = "abcdefghijaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$$$$$$$$$$$$$$$$$$$$$$$$";
        return new string(Enumerable.Repeat(chars, length)
          .Select(s => s[random.Next(s.Length)]).ToArray());
    }
    public static string forbiddenRandomString(int length)
    {
        const string chars = " ⇔£¥€©®™†‡§¶°…–—±×÷¼⅓½⅔¾μπ←↑→↓↔↵⇐⇒⇓⇔♠♣♥♦abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$";
        return new string(Enumerable.Repeat(chars, length)
          .Select(s => s[random.Next(s.Length)]).ToArray());
    }
    private static Random random = new Random();
}

