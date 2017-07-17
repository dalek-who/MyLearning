import java.text.DecimalFormat;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		int i = 1, num = 0, sum = 0;//i用于for以及while循环，num人数，sum总权值
		double money = 0, rmoney = 0;//money总金额，rmoney校验金额是否输入合法
		Scanner input = new Scanner(System.in);
		DecimalFormat tn = new DecimalFormat("0.00");//两位小数的格式，即金额最精确到分
		System.out.print("请输入总金额：");
		while(i == 1){
			money = input.nextDouble();//输入money金额
			rmoney = Double.valueOf(tn.format(money));//money两位小数前的数据
			if(money == rmoney && money > 0)//金额是最多精确到分，并且大于0
				i = 0;
			else System.out.print("输入不合法，请再次输入：");
		}
		i = 1;
		System.out.print("请输入总人数：");
		while(i == 1){
			num = input.nextInt();//输入num人数
			if(money * 100 - num > 0.0 && num > 0)//每个人至少得有1分，并且正整数个人
				i = 0;
			else System.out.print("输入不合法，请再次输入：");
		} 
		int[] weight = new int[num];
		for(i = 0 ; i < num ; i++) {
			weight[i] = (int) ((Math.random()*100+1));//随机每个人的权值
			sum = sum + weight[i];//计算总权值
		}
		double[] value = new double[num];
		System.out.println("红包金额分别为：");
		for(i = 0 ; i < num ; i++) {
			rmoney = weight[i] * money / sum;//计算每人分到的钱
			value[i] = Double.valueOf(tn.format(rmoney));//保留到两位小数
			if(value[i] == 0.00)//不能没分到钱
				value[i] = 0.01;
			else if(value[i] > money - (num - 1) / 100)//给其他人至少留每人1分
				value[i] = money - (num - 1) / 100;
			money = money - value[i];//减去用掉金额，下行减去用掉的权值
			sum = sum - weight[i];//目的把所有钱都分掉，与最后一个人拿走剩下的一样
			System.out.printf("%2d : %.2f\r\n",i+1,value[i]);//输出
		}		
		}

	private static double doublevalueof(String format) {
		// TODO Auto-generated method stub
		return 0;
	}
		
}
