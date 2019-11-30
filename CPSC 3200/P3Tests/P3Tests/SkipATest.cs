using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace P3Tests
{
	[TestClass]
	public class skipATest
	{
		[TestMethod]
		public void yieldTest()
		{
			int[] forbidden = { };
			arithS a = new skipA(2, forbidden, 0, 2);
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
