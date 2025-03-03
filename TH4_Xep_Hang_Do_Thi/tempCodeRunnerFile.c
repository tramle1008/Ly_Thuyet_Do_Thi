List l;
    make_null(&l);
    l = topo(&G);
    for (int i = 1; i <= l.size; i++)
    {
        printf("%d ", element_at(&l, i));
    }