// ignore_for_file: prefer_const_constructors

import 'package:flutter/material.dart';
import 'constants.dart';

class DisplayCard extends StatelessWidget {
  DisplayCard({required this.cardChild});

  final Widget cardChild;

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(8.0),
      child: Container(
        padding: EdgeInsets.all(20.0),
        child: cardChild,
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(10.0),
          color: kInactiveColor,
        ),
      ),
    );
  }
}