import java.util.Scanner;
public class ElectricBill{
    public static void main(String args[]){
        Scanner tej =new Scanner(System.in);
        System.out.println("enter the units");
        int unit=tej.nextInt();
        double total=0;
        double bill=0;

        int due=tej.nextInt();
        if(unit<50){
            bill=unit*0;
        }
        else if(unit<100)
        {
            bill=50*0+(unit-50)*3;
        }
        else if(unit<150){
            bill=50*0+(100-50)*3+(unit-100)*5;
        }
        else if(unit<200){
            bill=50*0+(100-50)*3+(150-100)*5+(unit-150)*8;
        }
        else if(unit<250)
        {
            bill=50*0+(100-50)*3+(150-100)*5+(200-150)*8+(unit-200)*10;
        }
        else if(unit>250){
            bill=50*0+(100-50)*3+(150-100)*5+(200-150)*8+(250-200)*10+(unit-250)*20;
        }

        //adding due als0
        if(due==0){
        bill = bill - (bill*0.05);
        }
        else{
             bill=bill+(bill*0.1);
        }
        System.out.println("the bill for " +unit+ " units. The cost is" +bill);
        

    }
}