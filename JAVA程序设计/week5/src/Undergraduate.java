public class Undergraduate extends Student{
    double aver;        //大学课程平均值

    @Override
    public boolean getPass() {
        if(aver>=60)status=true;
        else status=false;
        return status;
    }

    @Override
    public double computeAverage() {
        int count=score.length;
        double sum=0;
        for(int i=0;i<count;i++){
            sum+=score[i];
        }
        aver=sum/count;
        return aver;
    }

    @Override
    public String getDegree() {
        getPass();
        String res="";
        if(status==true)res=Constants.ISSUE_UNDERGRADUATE_DEGREE;
        else res=Constants.UNSATISFACTORY_ISSUE_UNDERGRADUATE_DEGREE;
        return res;
    }
}
