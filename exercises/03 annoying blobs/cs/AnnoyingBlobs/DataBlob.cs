using System;
using System.Collections.Generic;
using System.Linq;

namespace AnnoyingBlobs
{
    public class DataBlob
    {
        public static DataBlob GetBlob()
        {
            return CreateOrReturnBlob();
        }

        public void AddData(int i)
        {
            data.Add(i);
        }

        public int GetDataAtPos(int p)
        {
            
            return data.ElementAt(p);
        }

        private static DataBlob CreateOrReturnBlob()
        {
            if (theBlob == null)
            {
                Console.WriteLine("Creating Blob");
                theBlob = new DataBlob();
                for (int i = 0; i < 20; i++)
                {
                    theBlob.AddData(i);
                }
            }

            return theBlob;
        }

        private DataBlob()
        {
            data = new List<int>();
        }

        private static DataBlob theBlob = null;
        private IList<int> data;

        public bool IsEmpty()
        {
            return !data.Any();
        }
    }
}
