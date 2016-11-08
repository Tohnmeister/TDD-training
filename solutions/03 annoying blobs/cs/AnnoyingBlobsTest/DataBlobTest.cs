using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AnnoyingBlobs
{
    [TestClass]
    public class DataBlobTest
    {
        [TestInitialize]
        public void SetUp()
        {
        }

        [TestCleanup]
        public void TearDown()
        {
        }

        [TestMethod]
        public void TestDataInitiallyEmpty()
        {
            DataBlob blob = DataBlob.GetBlob();

            Assert.IsTrue(blob.IsEmpty());
        }

    }
}
