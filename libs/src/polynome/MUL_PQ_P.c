unsigned long int MUL_PQ_P(struct mod_4 *sstruct,unsigned long int **alpha)
{
    DM_P tempPlnm = new DM_P();
        for(int i; i < mod_4.m; i++){
            tempPlnm.a[i] = MUL_QQ_Q(mod_4.a[i], alpha);
        }
        return tempPlnm;
}
