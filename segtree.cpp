#include <iostream>

struct node
{
	int l, r;
	int val;
	int lazy;
} seg[20];
int a[5];
inline void pushup(int cur)
{
	seg[cur].val = seg[cur << 1].val + seg[cur << 1 | 1].val;
}
inline void pushdown(int cur)
{
	if (seg[cur].lazy)
	{
		seg[cur << 1].val += seg[cur].lazy * (seg[cur << 1].r - seg[cur << 1].l + 1);
		seg[cur << 1 | 1].val += seg[cur].lazy * (seg[cur << 1 | 1].r - seg[cur << 1 | 1].l + 1);
		seg[cur << 1].lazy += seg[cur].lazy;
		seg[cur << 1 | 1].lazy += seg[cur].lazy;
		seg[cur].lazy = 0;
	}
}
void build(int cur, int l, int r)
{
	seg[cur].l = l;
	seg[cur].r = r;
	seg[cur].lazy = 0;
	if (l == r)
	{
		seg[cur].val = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	pushup(cur);
}
void add(int cur, int l, int r, int v)
{
	if (l <= seg[cur].l && seg[cur].r <= r)
	{
		seg[cur].lazy += v;
		seg[cur].val += (seg[cur].r - seg[cur].l + 1) * v;
		return;
	}
	pushdown(cur);
	int mid = (seg[cur].l + seg[cur].r) / 2;
	if (l <= mid)
		add(cur << 1, l, r, v);
	if (r > mid)
		add(cur << 1 | 1, l, r, v);
	pushup(cur);
}
int query(int cur, int l, int r)
{
	if (l <= seg[cur].l && seg[cur].r <= r)
		return seg[cur].val;
	pushdown(cur);
	int mid = (seg[cur].l + seg[cur].r) / 2;
	int ans = 0;
	if (l <= mid)
		ans += query(cur << 1, l, r);
	if (r > mid)
		ans += query(cur << 1 | 1, l, r);
	return ans;
}
int main()
{
	std::cin >> a[1] >> a[2];
	build(1, 1, 2);
	std::cout << query(1, 1, 2);
	return 0;
}

