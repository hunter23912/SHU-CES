public class Master extends Student implements Manageable{
    double aver;
    char thesisLevel;//论文等级ABCDE

    @Override
    public boolean getPass() {
        if(aver>=80&&thesisLevel<='C')status=true;
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
        System.out.println("论文等级:"+this.thesisLevel);
    }

    @Override
    public double computeAverage() throws MasterException {
        int count=score.length;
        double sum=1;
        boolean f=true;
        for(int i=0;i<count;i++){
            sum*=score[i];
            if(score[i]<0||score[i]>100){
                f=false;
            }
        }
        double cc=1.0/count;
        //System.out.println("倒数:"+cc);
        aver=Math.pow(sum,cc);
        try {
            if (!f) {
                throw new MasterException("【warning】：该学生某门课成绩不在0-100区间内！");
            } else if (this.thesisLevel != 'A' && this.thesisLevel != 'B' && this.thesisLevel != 'C' && this.thesisLevel != 'D' && this.thesisLevel != 'E') {
                throw new MasterException("【warning】该研究生学位等级不在A-E范围内");
            } else {
                this.aver = aver;
            }
        }catch (MasterException e){
            System.out.println(e.warnMess());
        }
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
