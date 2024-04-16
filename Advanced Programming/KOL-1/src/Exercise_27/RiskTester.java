package Exercise_27;

import java.io.InputStream;
import java.util.*;

class Risk{
    public Risk() {
    }

    public void processAttacksData(InputStream in) {
        Scanner scanner = new Scanner(in);

        int countPoints = 0;

        while (scanner.hasNext()){
            String line = scanner.nextLine();

            String[] players = line.split(";");

            int[] attackers = Arrays.stream(players[0].split("\\s+"))
                    .mapToInt(Integer::parseInt).sorted().toArray();

            int[] defenders = Arrays.stream(players[1].split("\\s+"))
                    .mapToInt(Integer::parseInt).sorted().toArray();

            int attackerPoints = 0;
            int defenderPoints = 0;

            for(int i = 0; i < 3; i++){
                if(attackers[i] > defenders[i])
                    attackerPoints++;
                else
                    defenderPoints++;
            }

            System.out.println(attackerPoints + " " + defenderPoints);
        }


    }
}

public class RiskTester {
    public static void main(String[] args) {
        Risk risk = new Risk();
        risk.processAttacksData(System.in);
    }
}
