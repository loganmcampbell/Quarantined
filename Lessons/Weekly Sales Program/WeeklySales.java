import java.util.Scanner;

public class WeeklySales
{
	public static int saleNumber = 0;

	public static void addSaleNumber ()
	{
		saleNumber = saleNumber + 1;
	}

    public static class Sale
    {
        // Name of Sale
        private String saleName = "";
        // Amount of Sale
        private double saleAmount = 0;
        // Day of Sale
        private String saleDay = "";
        // ID of Sale
        private final int saleId = WeeklySales.saleNumber;

        public Sale()
        {
        	addSaleNumber();
        }

        public int getSaleId()
        {
            return saleId;
        }

        public void setSaleAmount(double amount)
        {
            saleAmount = amount;
        }
        public double getSaleAmount()
        {
            return saleAmount;
        }
        public void setSaleDay(String day)
        {
            saleDay = day;
        }
        public String getSaleDay()
        {
            return saleDay;
        }
        public String getSaleName()
        {
            return saleName;
        }

        public void setSaleName(String name)
        {
            saleName = name;
        }

    }

    public static void calculateTotalSales(Sale[] sales)
    {
        double total = 0;


    }




    public static void main(String[] args) {
        System.out.println("* * W E E K L Y  S A L E S * *");
        int cycle = 0;
        Scanner reader0 = new Scanner(System.in);  // Reading from System.in
        System.out.print("how many sales this week?");
        int quantity = Integer.parseInt(reader0.nextLine());
        System.out.println("quantity of sales is : " + quantity);

        Sale[] sales = new Sale[quantity];
        while (cycle < quantity)
        {
            Sale currSale = new Sale();
            System.out.println("SALE ID # " + currSale.saleId);
            System.out.println("Enter in the sale name: ");
            String salesname = reader0.nextLine(); // Scans the next token of the input as an int.
            currSale.setSaleName(salesname);
            System.out.println(("SALE NAME : " + salesname));

            System.out.println("Enter in the sale amount : ");
            double salesamount = Double.parseDouble(reader0.nextLine());
            currSale.setSaleAmount(salesamount);
            System.out.println("SALE AMOUNT : " + salesamount);

            System.out.println("Enter in the sale day (M TU W TH F SA SU) : ");
            String salesday = reader0.nextLine();
            while ((!salesday.equals("M")) && (!salesday.equals("TU")) && (!salesday.equals("W")) && (!salesday.equals("TH")) && (!salesday.equals("F")) && (!salesday.equals("SA")) && (!salesday.equals("SU"))) {
                System.out.println("Enter the correct day : ");
                salesday = reader0.nextLine();
            }
            currSale.setSaleDay(salesday);
            System.out.println("SALE DAY : " + salesday);


            System.out.println("\n[x] S A L E [] P R O C E S S E D [x] :: #" + currSale.saleId);
            System.out.println("\n");
            sales[cycle] = currSale;
            cycle++;
        }

        System.out.println("TOTAL SALES FROM THIS WEEK :");
        calculateTotalSales(sales);

        reader0.close();
    }

}
