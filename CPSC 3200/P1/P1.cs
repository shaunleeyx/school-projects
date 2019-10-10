using System;

namespace Project1
{
    class MainClass
    {
        static Random random = new Random();
        const int SIZE = 5;
        public static void Main(string[] args)
        {
            intDiv[] a = createObj();
            testActive(a);

        }

        //creates intdiv array referencing intdiv objs
        static intDiv[] createObj()
        {
            int div;
            intDiv[] obj = new intDiv[SIZE];
            for (int i = 0; i < SIZE; i++)
            {
                div = random.Next(1, 10);
                Console.WriteLine("index " + i + " inputting div as :" + div);
                obj[i] = new intDiv(div);
            }
            Console.WriteLine();
            return obj;
        }

        //tests out test(),reset() for both active and perm
        static void testActive(intDiv[] arr)
        {
            Console.WriteLine("----- testing test() function -----\n");
            for (int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("index " + i);
                testTest(arr[i]);
                Console.WriteLine();

            }
            Console.WriteLine("----- testing reset() function -----\n");
            for (int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("index " + i);
                testReset(arr[i]);
                Console.WriteLine();
            }

            Console.WriteLine("----- testing perm inactive state function -----\n");
            for (int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("index " + i);
                testReset(arr[i]);
                Console.WriteLine();
            }

        }

        static void testTest(intDiv obj)
        {
            int num;
            
            for (int i = 0; i < SIZE; i++)
            {
                num = random.Next(1, 100);
                Console.WriteLine("testing num:" + num);
                Console.WriteLine("remainder:" + obj.test((uint)num) + "    active:" + obj.getActive() + "     Perm inactive:" + obj.getPerm() + "\n");
            }

        }
        static void testReset(intDiv obj)
        {
            obj.reset();
            Console.WriteLine("reset!   active:" + obj.getActive() + "     Perm inactive:" + obj.getPerm() + "\n");
        }
    }

}