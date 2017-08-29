package homework3.homework3;

import android.content.Context;

import java.util.ArrayList;
import java.util.Random;

/**
 * Created by Juan D. Cardozo on 2/19/2016.
 */
public class AppInfo {

        private static AppInfo instance = null;

        protected AppInfo() {
            // Exists only to defeat instantiation.
        }

        // Here are some values we want to keep global.
        public ArrayList<String> chatText;

        public static AppInfo getInstance(Context context) {
            if(instance == null) {
                instance = new AppInfo();
                instance.chatText = new ArrayList<String>();
                Random rn = new Random();
                SecureRandomString srs = new SecureRandomString();
                // How long a list do we make?
                int n = 4 + rn.nextInt(10);
                for (int i = 0; i < n; i++) {
                    instance.chatText.add(srs.nextString());
                }

            }
            return instance;
        }

    }
