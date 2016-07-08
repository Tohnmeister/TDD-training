using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AnnoyingBlobs
{
    public class BlobViewer
    {
        static void Main(string[] args)
        {
            DataDisplayer view = new DataDisplayer();
            DataAdder model = new DataAdder();

            for (int j = 0; j < 30; j++)
            {
                if ((j % 3) == 0)
                {
                    model.DoSomeAdding();
                }

                view.Tick();
            }

            Console.ReadKey();
        }
    }
}
