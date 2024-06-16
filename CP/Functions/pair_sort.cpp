
// Sort vector A such that B also sort in that order only

void pairsort(vi &a, vi &b, int n)
{
    vpii v(n);
    loop(i, 0, n)
    {
        v[i] = make_pair(a[i], b[i]);
    }
    sort(v.begin(), v.end());
    loop(i, 0, n)
    {
        a[i] = v[i].ff;
        b[i] = v[i].ss;
    }
}
