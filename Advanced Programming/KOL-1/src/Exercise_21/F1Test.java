package Exercise_21;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;

class Timer{
    private int minutes;
    private int seconds;
    private int milliseconds;

    public Timer(int minutes, int seconds, int milliseconds) {
        this.minutes = minutes;
        this.seconds = seconds;
        this.milliseconds = milliseconds;
    }

    public int getTimeInMilliseconds(){
        return this.milliseconds + (this.seconds * 1000) + (this.minutes * 60000);
    }

    public String getTime(){
        return String.format("%d:%02d:%03d", minutes, seconds, milliseconds);
    }

}

class Racer{
    private String name;
    private List<Timer> times;

    public Racer(String name, List<Timer> times) {
        this.name = name;
        this.times = times.stream()
                .sorted(Comparator
                        .comparing(Timer::getTimeInMilliseconds))
                .collect(Collectors.toList());
    }

    public int bestTime(){
        return times.get(0).getTimeInMilliseconds();
    }

    @Override
    public String toString() {
        return String.format("%-10s %10s", name, times.get(0).getTime());
    }
}

class RacerFactory{
    public static Racer createRacer(String line){
        String[] lines = line.split("\\s+");

        String name = lines[0];

        List<Timer> timers = new ArrayList<>();

        for(int i = 1; i < lines.length; i++){
            String[] time = lines[i].split(":");

            int minutes = Integer.parseInt(time[0]);
            int seconds = Integer.parseInt(time[1]);
            int milliseconds = Integer.parseInt(time[2]);

            timers.add(new Timer(minutes, seconds, milliseconds));
        }

        return new Racer(name, timers);
    }
}

class F1Race {
    private List<Racer> racers;

    public F1Race() {
        racers = new ArrayList<>();
    }


    public void readResults(InputStream in) {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));

        racers = br.lines()
                .map(RacerFactory::createRacer)
                .collect(Collectors.toList());

        racers = racers.stream()
                .sorted(Comparator
                        .comparing(Racer::bestTime))
                .collect(Collectors.toList());
    }

    public void printSorted(PrintStream out) {
        PrintWriter pw = new PrintWriter(out, true);
        AtomicInteger i = new AtomicInteger(1);

        racers.forEach(r -> pw.printf("%d. %s", i.getAndIncrement(), r));
    }
}


public class F1Test {

    public static void main(String[] args) {
        F1Race f1Race = new F1Race();
        f1Race.readResults(System.in);
        f1Race.printSorted(System.out);
    }

}
