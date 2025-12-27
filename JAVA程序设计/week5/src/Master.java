public class Master extends Student{
    double aver;
    char thesisLevel;//论文等级ABCDE

    @Override
    public boolean getPass() {
        if(aver>=80&&thesisLevel>='C')status=true;
        else status=false;
        return status;
    }

    @Override
    public double computeAverage() {
        int count=score.length;
        double sum=1;
        for(int i=0;i<count;i++){
            sum*=score[i];
        }
        double cc=1.0/count;
        //System.out.println("倒数:"+cc);
        aver=Math.pow(sum,cc);
        return aver;
    }

    @Override
    public String getDegree() {
        getPass();
        String res="";
        if(status==true)res=Constants.ISSUE_MASTER_DEGREE;
        else res=Constants.UNSATISFACTORY_ISSUE_MASTER_DEGREE;
        return res;
    }
}
