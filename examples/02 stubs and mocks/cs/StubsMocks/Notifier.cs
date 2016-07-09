using System;
using System.Collections.Generic;

namespace StubsMocks
{
    class Notifier
    {
        private IList<IResponseHandler> responseHandlers = new List<IResponseHandler>();

        public void Add(IResponseHandler subscriber)
        {
            responseHandlers.Add(subscriber);
        }

        public void Publish(string message)
        {
            foreach (var handler in responseHandlers)
            {
                Console.WriteLine($"Notifying {handler.Name} with message: {message}");
                handler.Receive(message);
            }
        }
    }
}
