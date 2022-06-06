class hi implements Runnable{
    public void run()
    {
        for (int i=0; i<5; i++)
        {
            System.out.println("hi");
           try{ Thread.sleep(500);} catch(Exception e){}
        }
    }
}
class hello  implements Runnable{
    public void run()
    {
        for (int i=0; i<5; i++)
        {
            System.out.println("hello");
            try{ Thread.sleep(500);} catch(Exception e){}
        }
    }
}
public class Main
{
	public static void main(String[] args) {
	    hi h= new hi();
	    hello hel = new hello();
	    Thread t1=new Thread(h);
	    Thread t2 = new Thread(hel);
	    t1.start();
	     try{ Thread.sleep(10);} catch(Exception e){}
	    t2.start();
	}
}
