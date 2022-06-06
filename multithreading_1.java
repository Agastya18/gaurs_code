class hi extends Thread{
    public void run()
    {
        for (int i=0; i<5; i++)
        {
            System.out.println("hi");
           try{ Thread.sleep(500);} catch(Exception e){}
        }
    }
}
class hello  extends Thread{
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
	    h.start();
	     try{ Thread.sleep(10);} catch(Exception e){}
	    hel.start();
	}
}
