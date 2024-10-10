class Main
{
    public static void main(String [] args)
    {
        Main m = new Main();
        m.Hanoi(68,"SOURCE","AUXILARY","DESTINATION");
    }
    public void Hanoi(int disc,String Source,String Auxilary,String Destination)
    {
        if(disc == 1)
        {
            System.out.println("Move Disc "+disc+" From "+Source+" to "+Destination);
            return;
        }
        Hanoi(disc-1,Source,Destination,Auxilary);
        System.out.println("Move Disc "+disc+" From "+Source+" to "+Destination);
        Hanoi(disc-1,Auxilary,Source,Destination);
    }
}
