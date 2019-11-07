/*Author:Lee,Shaun
 * CPSC 3200
 * Version 3.0
 * 
 * Description: P2.cs(driver) will be testing all the functionality of MultiQ.cs, range.cs, and Factor.cs's functionalities. 
 * 
 * range.cs:
 * 1.rangeFunctionsTest() will ping 20 times to 5 range objects and it will print out the statistics for each of the 5 range objects.
 * 2.rangeTestCases(): test cases the ping() function to see if it works the same way as if you do it manually
 * 
 * multiQ.cs:
 * 1.multiQFunctionsTest():loads 100 entries in a multiQ object to see if the resize() works and then pop 100 entries for the pop() function
 * 2.multiQTestCase:test cases the query() function to see if it works the same way as if you do it manually
 */
using System;

namespace P2
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            rangeFunctionsTest();
            rangeTestCases();
            multiQFunctionsTest();
            multiQTestCases();
        }
        //This is for testing out all the function in range class (ping)
        static void rangeFunctionsTest()
        {
            Console.WriteLine("\t-------- rangeFunctionsTest() --------");
            Random rng = new Random();
            range[] array = new range[5];
            for (int i = 0; i < 5; i++)
            {
                array[i] = new range(rng.Next(1, 10),rng.Next(1, 10)); //chose small factors since it would be more likely in the test cases since 2 factors
            }
            for (int j = 0; j < 5; j++)
            {
                Console.WriteLine("-- TEST:"+(j+1) + " --");
                for (int i = 0; i < 20; i++)
                {
                    Console.WriteLine((array[j].ping(rng.Next(2, 300))));

                }
            }
            for (int j = 0; j < 5; j++)
            {
                Console.WriteLine(array[j].getStats());
            }
            Console.WriteLine();


        }
        //Test to see if the test case of range class matches if you manually do the same thing
        static void rangeTestCases()
        {
            Console.WriteLine("\t-------- rangeTestCases() --------");
            Random rng = new Random();
            int factortemp1 = rng.Next(1, 25);
            int factortemp2 = rng.Next(1, 25);
            int pingtemp1;
            range test = new range(factortemp1, factortemp2);
            for(int i = 0; i < 100; i++)
            {
                pingtemp1 = rng.Next(2, 100);
                Console.WriteLine(test.ping(pingtemp1) == (pingtemp1 % factortemp1 == 0 && pingtemp1 % factortemp2 == 0));
            }


        }
        //This is for testing out all the functions in MultiQ (resize(),query(),push(),pop())
        static void multiQFunctionsTest()
        {
            Console.WriteLine("\t-------- multiQFunctionsTest() --------");
            Random rng = new Random();
            multiQ test = new multiQ();
            Console.WriteLine("-- 100 entries into multiQ object --");
            for (int i = 0; i < 100; i++)
            {
                test.pushFactor(rng.Next(1, 100));
            }
            test.query(rng.Next(1, 50));
            Console.WriteLine("capacity of array intially is 5 and my count is " + test.getCount());
            Console.WriteLine("-- popping 100 factors from object --");
            for (int i = 0; i < 100; i++)
            {
                test.popFactor();
            }
            Console.WriteLine("My count is " + test.getCount());
            Console.WriteLine(test.printStats());
            Console.WriteLine();
        }
        //Test to see if the test case of multiQ class matches if you manually do the same thing
        static void  multiQTestCases()
        {
            Console.WriteLine("\t-------- multiQTestCases() --------");
            Random rng = new Random();
            int count;
            int querytemp;
            int temp;
            int factortemp1 = rng.Next(1, 20);
            int factortemp2 = rng.Next(1, 20);
            int factortemp3 = rng.Next(1, 20);
            multiQ test = new multiQ();
            Console.WriteLine("Factor1:" + factortemp1 + " Factor2:" + factortemp2 + " Factor3:" + factortemp3);
            test.pushFactor(factortemp1);
            test.pushFactor(factortemp2);
            test.pushFactor(factortemp3);
            for (int i = 0; i < 100; i++)
            {
                querytemp = rng.Next(1, 200);
                count = 0;
                temp = test.query(querytemp);
                if (querytemp % factortemp1 == 0) count++;
                if (querytemp % factortemp2 == 0) count++;
                if (querytemp % factortemp3 == 0) count++;

                Console.WriteLine("Num:" + querytemp + " freq:" + temp + "\tcount:" + count + "\t EQUAL?:" + (count == temp));
            }

            Console.WriteLine(test.printStats());
        }
    }
}
        