package <missing>;

public class GlobalMembers
{
	/*
	 * er_cha_shu.cpp
	 * ?? - ???
	 * ??????????1, 2, 3, ...???????????????????????????1?????????
	 * ????????10????????(10, 5, 2, 1)??4????????(4, 2, 1)?????1????????
	 * ???????1???????(1)???????x?y???????????????(x1, x2, ... ,1)?
	 * (y1, y2, ... ,1)??????x = x1?y = y1?????????????i?j????xi ? yj???
	 * ?xi = yj , xi + 1 = yj + 1, xi + 2 = yj + 2,... ??????????x?y???xi????yj??
	 *  Created on: 2013-11-20
	 *      Author: ???
	 */
	public static int find(int x, int y)
	{ // ???????
		if (x == y)
		{
			return x; // ??????????
		}
		while ((x /= 2) > y)
		{
		} // ?????????? /2 ?????????????????????
		return find(y, x);
	}
	public static int Main()
	{
		int x;
		int y;
		x = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
		y = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
		System.out.print((x > y != 0 ? find(x, y) : find(y, x)));
		System.out.print("\n");
		return 0;
	}

}

