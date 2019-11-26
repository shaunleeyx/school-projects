using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace P3Tests
{
    [TestClass]
    public class arithSTest
    {
        [TestMethod]//threshold = 5
        public void thresholdandForbiddenTest()
        {
            int[] forbidden = { 2, 4, 6, 8, 10, 12,14,16};
            arithS a = new arithS(2, forbidden);
            a.switchAdvance();
            Assert.AreEqual(a.yield(), 2);
            Assert.AreEqual(a.yield(), 4);
            Assert.AreEqual(a.yield(), 6);
            Assert.AreEqual(a.yield(), 8);
            Assert.AreEqual(a.yield(), 10);
            Assert.AreEqual(a.yield(), 12);
            Assert.AreEqual(a.yield(), 12); 
            Assert.AreEqual(a.yield(), 12); 
            Assert.AreEqual(a.yield(), 18);

        }
        [TestMethod]
        public void statechangeTest()
        {
            int[] forbidden = {};
            arithS a = new arithS(3, forbidden);
            a.switchStuck();
            Assert.AreEqual(a.yield(), 0);
            a.switchAdvance();
            Assert.AreEqual(a.yield(), 3);
            Assert.AreEqual(a.yield(), 6);
            a.switchRetreat();
            Assert.AreEqual(a.yield(), 3);
            Assert.AreEqual(a.yield(), 0);
        }

        [TestMethod]
        public void numGenTest()
        {
            int[] forbidden = {};
            arithS a = new arithS(3, forbidden);
            a.yield();
            Assert.AreEqual(a.numGen(), 1);
        }

        [TestMethod]
        public void yieldTest()
        {
            int[] forbidden = {};
            arithS a = new arithS(2, forbidden);
            a.switchAdvance();
            Assert.AreEqual(a.yield(), 2);
            Assert.AreEqual(a.yield(), 4);
            Assert.AreEqual(a.yield(), 6);
            Assert.AreEqual(a.yield(), 8);
            Assert.AreEqual(a.yield(), 10);
            Assert.AreEqual(a.yield(), 12);
            Assert.AreEqual(a.yield(), 14);
            Assert.AreEqual(a.yield(), 16);
            Assert.AreEqual(a.yield(), 18);
            arithS b = new arithS(3, forbidden);
            b.switchAdvance();
            Assert.AreEqual(b.yield(), 3);
            Assert.AreEqual(b.yield(), 6);
            Assert.AreEqual(b.yield(), 9);
            Assert.AreEqual(b.yield(), 12);
            Assert.AreEqual(b.yield(), 15);
            Assert.AreEqual(b.yield(), 18);
            Assert.AreEqual(b.yield(), 21);
            Assert.AreEqual(b.yield(), 24);
            Assert.AreEqual(b.yield(), 27);
            b.switchRetreat();
            Assert.AreEqual(b.yield(), 24);
            Assert.AreEqual(b.yield(), 21);
            Assert.AreEqual(b.yield(), 18);
            Assert.AreEqual(b.yield(), 15);
            Assert.AreEqual(b.yield(), 12);
            Assert.AreEqual(b.yield(), 9);
        }

        [TestMethod]
        public void resetCheck()
        {
            int[] forbidden = { };
            arithS a = new arithS(2, forbidden);
            Assert.AreEqual(a.numGen(), 0);
            Assert.AreEqual(a.getmodechangeCount(), 0);
            a.switchAdvance();
            a.yield();
            a.yield();
            a.yield();
            a.yield();
            a.yield();
            Assert.AreEqual(a.numGen(), 5);
            Assert.AreEqual(a.getmodechangeCount(), 1);
            a.reset();
            Assert.AreEqual(a.numGen(), 0);
            Assert.AreEqual(a.getmodechangeCount(), 0);
        }
        [TestMethod]
        public void getmodechangeCountTest()
        {
            int[] forbidden = { };
            arithS a = new arithS(2, forbidden);
            a.switchAdvance();
            Assert.AreEqual(a.getmodechangeCount(), 1);
            a.switchStuck();
            Assert.AreEqual(a.getmodechangeCount(), 2);
            a.switchRetreat();
            Assert.AreEqual(a.getmodechangeCount(), 3);
            a.switchAdvance();
            Assert.AreEqual(a.getmodechangeCount(), 4);
            a.switchStuck();
            Assert.AreEqual(a.getmodechangeCount(), 5);
            a.switchRetreat();
            Assert.AreEqual(a.getmodechangeCount(), 6);
        }

    }
    [TestClass]
    public class oscillateATest
    {
        [TestMethod]
        public void advanceyieldTest()
        {

            int[] forbidden = { };
            arithS a = new oscillateA(2, forbidden);
            a.switchAdvance();
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);

        }
        [TestMethod]
        public void retreatyieldTest()
        {

            int[] forbidden = { };
            arithS a = new oscillateA(2, forbidden);
            a.switchRetreat();
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);

        }
        [TestMethod]
        public void resetTest()
        {
            int[] forbidden = { };
            arithS a = new oscillateA(2, forbidden);
            a.switchAdvance();
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            a.reset();
            a.switchAdvance();
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);

        }
    }
    [TestClass]
    public class skipATest
    {
        [TestMethod]
        public void yieldTest()
        {
            int[] forbidden = {};
            arithS a = new skipA(2, forbidden,2);
            a.switchAdvance();
            Assert.AreEqual(a.yield(), 6);
            Assert.AreEqual(a.yield(), 12);
            Assert.AreEqual(a.yield(), 18);
            Assert.AreEqual(a.yield(), 24);
            a.switchRetreat();
            Assert.AreEqual(a.yield(), 18);
            Assert.AreEqual(a.yield(), 12);
            Assert.AreEqual(a.yield(), 6);
            Assert.AreEqual(a.yield(), 0);
        }
    }
}
