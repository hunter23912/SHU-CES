public class Undergraduate extends Student implements Manageable{
    double aver;        //大学课程平均值

    @Override
    public boolean getPass() {
        if(aver>=60)status=true;
        else status=false;
        return status;
    }

    @Override
    public void printInfo() {
        System.out.println("姓名："+this.getName());
        System.out.println("性别："+this.getGender());
        System.out.println("出生日期："+this.getBirthDay());
        System.out.println("学校："+this.getSchool());
        System.out.println("学号："+this.getStuId());
        System.out.println("学生类别："+this.getCategory());
    }

    @Override
    public double computeAverage() throws UndergraduateException {
        int count=score.length;
        double sum=0;
        boolean f=true;
        for(int i=0;i<count;i++){
            sum+=score[i];
            if(score[i]<0||score[i]>100){
                f=false;
            }
        }
        aver=sum/count;
        if(!f){
            try {
                throw new UndergraduateException();
            }catch (UndergraduateException e){
                System.out.println(e.warnMess());
            }

        }else{
            this.aver=aver;
        }
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
