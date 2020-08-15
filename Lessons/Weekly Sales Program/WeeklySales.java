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
        String[] DAYS = new String[]{ "M","TU","W","TH","F","SA","SU"};
        double [] totalDay = new double[DAYS.length];
        int [] numberOfSales = new int[DAYS.length];
        for (Sale sale : sales) {
            int count = 0;
            for (int y = 0; y < DAYS.length; y++) {
                if (sale.getSaleDay().equals(DAYS[y])) {
                    System.out.println(("-------------------------------------------"));
                    System.out.println("SALE ID: " + sale.getSaleId());
                    System.out.println("SALE NAME: " + sale.getSaleName());
                    System.out.println("SALE AMOUNT: " + sale.getSaleAmount());
                    System.out.println("SALE DAY: " + sale.getSaleDay());
                    System.out.println(("-------------------------------------------"));
                    count++;
                    totalDay[y] += sale.getSaleAmount();
                    numberOfSales[y] += count;
                }
            }
        }

        double largestSum = 0;
        int largestSumDay = 0;
        for(int x = 0; x < totalDay.length; x++)
        {
            System.out.println(DAYS[x] + ":\t contains => " + totalDay[x]);
            if (largestSum < totalDay[x])
            {
                largestSum = totalDay[x];
                largestSumDay = x;
            }
        }
        System.out.println("************************************");
        System.out.println("|LARGEST SUM WAS ON " + DAYS[largestSumDay] + " WITH " + largestSum + "    |");
        System.out.println("************************************");

        double largestAverage = 0;
        int largestAvgDay = 0;
        for(int day = 0; day < DAYS.length; day++)
        {
            double average = (totalDay[day]/numberOfSales[day]);
            if (largestAverage < average)
            {
                largestAverage = average;
                largestAvgDay = day;
            }
            System.out.println(DAYS[day] + " ::\t AVERAGE = " + average);
        }

        System.out.println("-----------------------------------");
        System.out.println("| LARGEST AVERAGE : " + DAYS[largestAvgDay] + " with " + largestAverage + "   |");
        System.out.println("-----------------------------------");

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
            System.out.println("=============");
            System.out.println("|SALE ID # " + currSale.saleId + "|");
            System.out.println("=============");

            System.out.print("Enter in the sale name: ");
            String salesname = reader0.nextLine(); // Scans the next token of the input as an int.
            currSale.setSaleName(salesname);
            System.out.println(("SALE NAME : " + salesname));

            System.out.print("Enter in the sale amount : ");
            double salesamount = Double.parseDouble(reader0.nextLine());
            currSale.setSaleAmount(salesamount);
            System.out.println("SALE AMOUNT : " + salesamount);

            System.out.print("Enter in the sale day (M TU W TH F SA SU) : ");
            String salesday = reader0.nextLine();
            while ((!salesday.equals("M")) && (!salesday.equals("TU")) && (!salesday.equals("W")) && (!salesday.equals("TH")) && (!salesday.equals("F")) && (!salesday.equals("SA")) && (!salesday.equals("SU"))) {
                System.out.print("Enter the correct day : ");
                salesday = reader0.nextLine();
            }
            currSale.setSaleDay(salesday);
            System.out.println("SALE DAY : " + salesday);

            System.out.println("------------------------------------------------");
            System.out.println("|[X]||[ S A L E * P R O C E S S E D ]||[X] :: #" + currSale.saleId + "|");
            System.out.println("------------------------------------------------");
            System.out.println("\n");
            sales[cycle] = currSale;
            cycle++;
        }

        System.out.println("TOTAL SALES FROM THIS WEEK :");
        calculateTotalSales(sales);

        reader0.close();
    }

}
