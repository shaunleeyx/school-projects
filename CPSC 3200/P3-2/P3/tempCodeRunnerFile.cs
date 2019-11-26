using System;
/* Driver Overview:This driver starts off by generating 5 of each type of arithS object. I pass the sequence number and forbidden set
 *                into the arithS,oscillator object. I pass the sequence number,forbidden set and skip number into the skipA obj. I output
 *                the sequence number, forbidden set, and skip number at the top of the driver indexed by the heterogenous collection. Every
 *                Arith Obj starts at 0. sequence number is the incrementor value for the arithS obj.Skip number is the number that makes the
 *                SkipA obj skip an amount of increments.It tests each object by calling yield 7 times while its advance, 7 while its stuck and
 *                7 while its in retreat. it also checks the stats before and after and also after reset. I believe that this will test all the
 *                functionalities of these 3 classes.By default every arithS obj is set to stuck
 */
namespace P3
{
    class MainClass
    {
        static Random random = new Random();

        public static void Main(string[] args)
        {
            const int SIZE = 15;
            arithS[] arr = new arithS[SIZE];
            arr = arithSarrGen();
            arithSTest(arr);
        }

        //PRECONDITION:arithS array
        //POSTCONDITION:it tests out each element of the arithS array
        public static void arithSTest(arithS[] arr)
        {
            Console.WriteLine("---- Testing arithSObjects ----");

            const int SIZE = 15;
            for (int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("\n\t\t\tindex:" + (i) + "\n");
                if (i % 3 == 0)//arithS
                {
                    Console.WriteLine("type:arithS obj");
                    test(arr[i]);
                }
                else if (i % 3 == 1)//oscillateA
                {
                    Console.WriteLine("type:oscillateA obj");
                    test(arr[i]);
                }
                else//SkipA
                {
                    Console.WriteLine("type:SkipA obj");
                    test(arr[i]);
                }
            }
        }
        //PRECONDITION: takes a arithSobj
        //POSTCONDITION: executes a sequence of tests regarding yield and statechange of the arithSobj
        public static void test(arithS obj)
        {

            printStats(obj);
            Console.WriteLine("\n-default state:Stuck-");
            Console.WriteLine("yield:"+obj.yield());
            Console.WriteLine("\n-State change to advance-");
            obj.switchAdvance();
            yieldLoop(obj);
            Console.WriteLine("\n-State Change:Stuck-");
            obj.switchStuck();
            yieldLoop(obj);
            Console.WriteLine("\n-State Change:Retreat-");
            obj.switchRetreat();
            yieldLoop(obj);
            Console.WriteLine();
            printStats(obj);
            obj.reset();
            Console.WriteLine("object called reset()");
            printStats(obj);
        }
        //PRECONDITION: takes in a arithS obj
        //POSTCONDITION: calls yield 7 times on the arithS obj
        public static void yieldLoop(arithS obj)
        {
            const int SIZE = 7;
            for (int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("yield:" + obj.yield());
            }
        }
        //PRECONDITION: arithS obj
        //POSTCONDITION: prints out the stats of the arithS obj
        public static void printStats(arithS obj)
        {
            Console.WriteLine("modechangeCount: {0}  numbers generated from yield: {1}", obj.getmodechangeCount(), obj.numGen());
        }
        //PRECONDITION:nothing 
        //POSTCONDITION:generates an int of size 5 of random numbers from 1 to 100
        public static int[] forbiddenGen()
        {
            const int SIZE = 5;
            int temp;
            int[] forbidden = new int[SIZE];
            Console.Write("values in forbidden:");
            for (int i = 0; i < SIZE; i++)
            {
                temp = random.Next(1, 100);
                Console.Write(temp + " ");
                forbidden[i] = temp;
            }
            Console.WriteLine("\n");
            return forbidden;

        }
        //PRECONDITION:nothing
        //POSTCONDITION: generates a heterogenous collection
        public static arithS[] arithSarrGen()
        {
            Console.WriteLine("\n ---- Generating ArithS objects ----");
            const int SIZE = 15;
            arithS[] obj = new arithS[SIZE];
            for (int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("index:"+(i));
                if(i%3 == 0)//arithS
                {
                    obj[i] = arithSgen();
                }
                else if(i%3 == 1)//oscillateA
                {
                    obj[i] = oscillateAgen();
                }
                else//SkipA
                {
                    obj[i] = skipAgen();
                }
            }
            return obj;
        }
        //PRECONDITION:none
        //POSTCONDITION:generates a arithS obj
        public static arithS arithSgen()
        {
            const int SEQMIN = 0;
            const int SEQMAX = 20;
            int sequence = random.Next(SEQMIN, SEQMAX);
            Console.WriteLine("sequence number:{0}", sequence);
            arithS obj = new arithS(sequence, forbiddenGen());
            return obj;
        }
        //PRECONDITION:none
        //POSTCONDITION:generates oscillateA obj
        public static oscillateA oscillateAgen()
        {
            const int SEQMIN = 0;
            const int SEQMAX = 20;
            int sequence = random.Next(SEQMIN, SEQMAX);
            Console.WriteLine("sequence number:{0}", sequence);
            oscillateA obj = new oscillateA(sequence, forbiddenGen());
            return obj;
        }
        //PRECONDITION:none
        //POSTCONDITION:generates a skipA obj
        public static skipA skipAgen()
        {
            const int SEQMIN = 0;
            const int SEQMAX = 20;
            int sequence = random.Next(SEQMIN, SEQMAX);
            Console.WriteLine("sequence number:{0}", sequence);
            const int SKIPMIN = 1;
            const int SKIPMAX = 10;
            int skipvalue = random.Next(SKIPMIN, SKIPMAX);
            Console.WriteLine("skipvalue number:{0}", skipvalue);
            skipA obj = new skipA(sequence, forbiddenGen(),skipvalue);
            return obj;
        }
    }

}
