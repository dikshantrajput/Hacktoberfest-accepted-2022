import 'package:demo_login/provider/dashboard_provider.dart';
import 'package:demo_login/screen/appointment.dart';
import 'package:demo_login/screen/clinics.dart';
import 'package:demo_login/screen/favorite.dart';
import 'package:demo_login/screen/feedback.dart';
import 'package:demo_login/screen/medical_record.dart';
import 'package:demo_login/screen/my_doctor.dart';
import 'package:demo_login/screen/saved.dart';
import 'package:demo_login/screen/settings.dart';
import 'package:demo_login/screen/user_profile.dart';
import 'package:demo_login/utils/appcolor.dart';
import 'package:demo_login/utils/style/animation.dart';
import 'package:demo_login/utils/style/style.dart';
import 'package:demo_login/utils/value/string.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

class AppDrawer extends StatefulWidget {
  const AppDrawer({Key? key}) : super(key: key);

  @override
  _AppDrawerState createState() => _AppDrawerState();
}

class _AppDrawerState extends State<AppDrawer> {
  @override
  Widget build(BuildContext context) {
    return Drawer(
        child: ListView(padding: EdgeInsets.zero, children: [
      DrawerHeader(
          decoration: const BoxDecoration(
            color: primarytheme,
          ),
          child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              crossAxisAlignment: CrossAxisAlignment.center,
              children: <Widget>[
                const Expanded(
                  child: CircleAvatar(
                    radius: 35,
                    //add user image here
                    backgroundImage: AssetImage('assets/images/avator.png'),
                  ),
                ),
                const SizedBox(
                  width: 10,
                ),
                Expanded(
                  flex: 2,
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: <Widget>[
                      Text(
                        context.watch<DashboardProvider>().userName,
                        overflow: TextOverflow.clip,
                        maxLines: 1,
                        style: overSizedFontWhite,
                      ),

                      GestureDetector(
                        onTap: () => Navigator.push(context,
                            SlideBottomTopTransitions(const Profile())),
                        child: const Text(view,
                            style: TextStyle(
                              color: Colors.white,
                            )),
                      ),

                      const Text("0% Completed") // recieve respond from server
                    ],
                  ),
                ),
              ])),
      ListTile(
        leading: const Icon(Icons.home),
        title: const Text(lblAppointment),
        trailing: const Icon(Icons.keyboard_arrow_right),
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const Appointment()),
          );
        },
      ),
      ListTile(
        leading: const Icon(Icons.record_voice_over),
        title: const Text(lblrecord),
        trailing: const Icon(Icons.keyboard_arrow_right),
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const MyedicalRecord()),
          );
        },
      ),
      ListTile(
        leading: const Icon(Icons.person),
        title: const Text(lbldoctor),
        trailing: const Icon(Icons.keyboard_arrow_right),
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const Mydoctor()),
          );
        },
      ),
      ListTile(
        leading: const Icon(Icons.local_hospital),
        title: const Text(lblClinic),
        trailing: const Icon(Icons.keyboard_arrow_right),
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const ClinicsScreen()),
          );
        },
      ),
      ListTile(
        leading: const Icon(Icons.favorite_border_outlined),
        title: const Text(lblFav),
        trailing: const Icon(Icons.keyboard_arrow_right),
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const Favorite()),
          );
        },
      ),
      ListTile(
        leading: const Icon(Icons.settings),
        title: const Text(lblSetting),
        trailing: const Icon(Icons.keyboard_arrow_right),
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const SettingScrren()),
          );
        },
      ),
      ListTile(
        leading: const Icon(Icons.feedback),
        title: const Text(lblFeedback),
        trailing: const Icon(Icons.keyboard_arrow_right),
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const FeedBack()),
          );
        },
      ),
      const Divider(),
    ]));
  }
}
