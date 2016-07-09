using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StubsMocks
{
    interface IResponseHandler
    {
        void Receive(string message);
        string Name { get; }
    }
}
