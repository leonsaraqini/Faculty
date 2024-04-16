package Exercise_7 ;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Times{
    private int hours;
    private int minutes;

    public Times(int hours, int minutes) {
        this.hours = hours;
        this.minutes = minutes;
    }

    public int getHoursInFormatAMPM(){
        if(hours > 12 || hours == 0)
            return Math.abs(hours - 12);
        else
            return hours;
    }

    public String getAMPMString(){
        String format;

        if(hours == 0 || hours < 12){
            format = "AM";
        }else{
            format = "PM";
        }

        return String.format("%2d:%02d %s", getHoursInFormatAMPM(), minutes, format);
    }

    public int getHours() {
        return hours;
    }

    public int getMinutes() {
        return minutes;
    }

    @Override
    public String toString() {
        return String.format("%2d:%02d", hours, minutes);
    }
}

class TimeTable{
    private List<Times>times;

    public TimeTable() {
        this.times = new ArrayList<>();
    }

    public void readTimes(InputStream in) throws UnsupportedFormatException, InvalidTimeException{
        Scanner scanner = new Scanner(in);

        while (scanner.hasNext()){
            String line = scanner.next();

            int mci = (int)Math.ceil(line.length() / 2.00) - 1;
            String sign = String.format("%s",line.charAt(mci));

            if(!sign.equals(".") && !sign.equals(":"))
                throw new UnsupportedFormatException(line);

            String[] lines;

            if(sign.matches(":")){
                lines = line.split(":");
            }else{
                lines = line.split("\\.");
            }

            int hours = Integer.parseInt(lines[0]);
            int minutes = Integer.parseInt(lines[1]);

            if(hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
                throw new InvalidTimeException(line);

            times.add(new Times(hours, minutes));
        }


    }

    public void writeTimes(PrintStream out, TimeFormat timeFormat) {
        times = times.stream()
                .sorted(Comparator
                        .comparing(Times::getHours)
                        .thenComparing(Times::getMinutes))
                .collect(Collectors.toList());

        PrintWriter pw = new PrintWriter(out, true);

        if(timeFormat == TimeFormat.FORMAT_24)
            times.forEach(pw::println);
        else
            times.forEach(c -> pw.println(c.getAMPMString()));

    }
}

class UnsupportedFormatException extends Exception{
    public UnsupportedFormatException(String message) {
        super(message);
    }
}

class InvalidTimeException extends Exception{
    public InvalidTimeException(String message) {
        super(message);
    }
}

public class TimesTest {

    public static void main(String[] args) {
        TimeTable timeTable = new TimeTable();
        try {
            timeTable.readTimes(System.in);
        } catch (UnsupportedFormatException e) {
            System.out.println("UnsupportedFormatException: " + e.getMessage());
        } catch (InvalidTimeException e) {
            System.out.println("InvalidTimeException: " + e.getMessage());
        }
        System.out.println("24 HOUR FORMAT");
        timeTable.writeTimes(System.out, TimeFormat.FORMAT_24);
        System.out.println("AM/PM FORMAT");
        timeTable.writeTimes(System.out, TimeFormat.FORMAT_AMPM);
    }

}

enum TimeFormat {
    FORMAT_24, FORMAT_AMPM
}
