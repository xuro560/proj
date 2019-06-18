using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication39
{
    class Program
    {
        static void Main(string[] args)
        {
            Task t = new Task();
            Resolve r = new Resolve();

            Console.WriteLine("Введите a: ");
            t.GetA = Convert.ToDouble(Console.ReadLine());
            if (t.GetA == 0)
            {
                Console.WriteLine("Деление на ноль!");
                Console.ReadKey();
                return;
            }

            Console.WriteLine("Введите b: ");
            t.GetB = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите c: ");
            t.GetC = Convert.ToDouble(Console.ReadLine());

            ReturnX returnX = new ReturnX();
            r = returnX.Solve(t);
            
            
            if (r.GetR)
            {
                Console.WriteLine("Действительные корни: x = " + r.GetX1);
                Console.WriteLine("\tx = " + r.GetX2);
                Console.ReadKey();
            }
            else
            {
                Console.WriteLine("Действительных корней нет.");
                Console.ReadKey();
            }

      
        }
    }

    public class Task
    {
        public double GetA { get; set; }
        public double GetB { get; set; }
        public double GetC { get; set; }
    }

    public class Resolve
    {
        public double GetX1 { get; set; }
        public double GetX2 { get; set; }
        public bool GetR { get; set; }
    }

    class ReturnX
    {
        double D;

        public Resolve Solve(Task task)
        {
            Resolve resolve = new Resolve();

            D = Math.Pow(task.GetB, 2) - 4 * task.GetA * task.GetC;
            if (D > 0 || D == 0)
            {
                resolve.GetX1 = (-task.GetB + Math.Sqrt(D)) / (2 * task.GetA);
                resolve.GetX2 = (-task.GetB - Math.Sqrt(D)) / (2 * task.GetA);
                resolve.GetR = true;
            }
            else
            {
                resolve.GetR = false;
            }

            return resolve;
        }

    }
}