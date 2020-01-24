using System;
/* Author:Shaun Lee
 * Driver Overview:Tests out the mangler classes and arithMangler class
 *
 */
namespace P6 {
    class MainClass {

        static Random random = new Random ();

        public static void Main (string[] args) {
            Test ();
        }

        public static void Test () {
            const int SIZE = 5;
            const int SIZE1 = 15;
            arithSMangler[] arithManglerArr = new arithSMangler[SIZE];
            mangler[] manglerArr = new mangler[SIZE1];
            Console.WriteLine("\n --- Test for mangler,puzzler,and amplifier ---\n");
            for (int i = 0; i < SIZE1; i++) {
                if (i % 3 == 0) {
                    manglerArr[i] = manglerGen ();
                    manglerTest (manglerArr[i]);
                } else if (i % 3 == 1) {
                    manglerArr[i] = puzzleGen ();
                    manglerTest (manglerArr[i]);
                } else {
                    manglerArr[i] = amplifierGen ();
                    manglerTest (manglerArr[i]);
                } 
            }


            Console.WriteLine(" --- Test for arithMangler ---\n");
            for (int i = 0; i < SIZE; i++) {
                arithManglerArr[i] = arithManglerGen();
                arithManglerTest(arithManglerArr[i]);

            }

        }
        
        public static void manglerTest (mangler obj) {
            int bValue = random.Next (0, 50);
            Console.WriteLine(" b:" + bValue);
            Console.WriteLine ("request test:" + obj.request (bValue) + "\n");
        }
        public static void arithManglerTest (arithSMangler obj) 
        {
            int bValue = random.Next (0, 50);
           int cValue = random.Next(1,10);
            Console.Write("changed clear to " + cValue + "\n");
            int skipValue = random.Next(1,10);
            Console.Write("changed skipvalue to" + skipValue + "\n"); 
            int num1 = random.Next(0,100);
            int num2 = random.Next(0,100);
            int num3 = random.Next(0,100);
            int[] arr = new int[]{num1,num2,num3};
            Console.WriteLine("fset:" + num1 + "," + num2 + "," + num3);
            obj.changeFset(arr);
           bValue = random.Next (0, 50);
            Console.Write(" b:" + bValue);
           Console.Write(" yield:" + obj.yield());
           Console.WriteLine(" request:" + obj.request(bValue));
           bValue = random.Next (0, 50);
            Console.Write(" b:" + bValue);
           Console.Write(" yield:" + obj.yield());
           Console.WriteLine(" request:" + obj.request(bValue));
           bValue = random.Next (0, 50);
            Console.Write(" b:" + bValue);
           Console.Write(" yield:" + obj.yield());
           Console.WriteLine(" request:" + obj.request(bValue) + "\n");


        }
        public static puzzler puzzleGen () {
            int xValue = random.Next (0, 50);
            int cValue = random.Next (0, 50);
            Console.Write("Puzzler\tx:" + xValue + " c:" + cValue);
            puzzler obj = new puzzler (xValue, cValue);
            return obj;
        }
        public static mangler manglerGen () {
            int xValue = random.Next (0, 50);
            Console.Write("Mangler\tx:" + xValue);
            mangler obj = new mangler (xValue);
            return obj;
        }
        public static amplifier amplifierGen () {
            int xValue = random.Next (0, 50);
            Console.Write("Amplifier x:" + xValue);
            amplifier obj = new amplifier (xValue);
            return obj;
        }
        public static arithSMangler arithManglerGen () {
            int arithNum = random.Next (0, 2);
            int manglerNum = random.Next (0, 2);
            int diffValue = random.Next (1, 10);
            int tholdValue = random.Next (1, 10);
            int xValue = random.Next (0, 50);
            String arithStr;
            String manglerStr;
            if(arithNum == 0) arithStr = "arithS";
            else if(arithNum == 1) arithStr = "oscillateA";
            else arithStr = "SkipA";
            if(manglerNum == 0) manglerStr = "mangler";
            else if(manglerNum == 1) manglerStr = "amplifier";
            else manglerStr = "puzzler";
            Console.WriteLine("arithType:" + arithStr + " manglerType:" + manglerStr + " diff:" + diffValue + " thold:" + tholdValue + " x:" + xValue + " c: 1 skipnum: 1 fset:{}");
            arithSMangler obj = new arithSMangler (arithNum, manglerNum, diffValue, tholdValue, xValue);
            obj.switchAdvance();
            return obj;
        }

    }
}
