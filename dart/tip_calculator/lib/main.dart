// ignore_for_file: prefer_const_constructors, prefer_const_literals_to_create_immutables

import 'package:flutter/material.dart';
import 'constants.dart';
import 'package:auto_size_text_field/auto_size_text_field.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'changing_button.dart';
import 'display_card.dart';

void main() {
  runApp(
    MaterialApp(
      debugShowCheckedModeBanner: false,
      title: "Tip Calculator by Dhruv Arora",
      home: TipCalculator(),
    ),
  );
}

class TipCalculator extends StatefulWidget {
  const TipCalculator({Key? key}) : super(key: key);

  @override
  State<TipCalculator> createState() => _TipCalculatorState();
}

class _TipCalculatorState extends State<TipCalculator> {
  final _textEditingController = TextEditingController();

  double _billAmount = 0.0;
  int _tipPercent = 10;
  int _split = 1;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: kInactiveColor,
        centerTitle: true,
        title: Text(
          "Tipsy",
          style: TextStyle(
            fontFamily: "Architects Daughter",
            fontWeight: FontWeight.bold,
            fontSize: 30.0,
            color: Color(0xFF0A502F),
          ),
        ),
      ),
      body: Center(
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: ListView(
            scrollDirection: Axis.vertical,
            children: <Widget>[
              Expanded(
                child: Row(
                  children: <Widget>[
                    Expanded(
                      child: DisplayCard(
                        cardChild: Column(
                          mainAxisAlignment: MainAxisAlignment.center,
                          crossAxisAlignment: CrossAxisAlignment.center,
                          children: [
                            Text(
                              "ENTER BILL AMOUNT",
                              textAlign: TextAlign.center,
                              style: kLabelTextStyle,
                            ),
                            Row(
                              mainAxisAlignment: MainAxisAlignment.center,
                              crossAxisAlignment: CrossAxisAlignment.center,
                              children: <Widget>[
                                Padding(
                                  padding: const EdgeInsets.only(right: 8.0),
                                  child: Text(
                                    "₹",
                                    style: kPrePostTextStyle,
                                  ),
                                ),
                                SizedBox(
                                  width: 90.0,
                                  child: AutoSizeTextField(
                                    onChanged: (String value) {
                                      _billAmount = double.parse(value);
                                    },
                                    onSubmitted: (String value) {
                                      _billAmount = double.parse(value);
                                    },
                                    controller: _textEditingController,
                                    minFontSize: 25.0,
                                    textAlign: TextAlign.center,
                                    textAlignVertical: TextAlignVertical.center,
                                    cursorRadius: Radius.circular(5.0),
                                    cursorColor: kActiveColor,
                                    style: kNumberStyle,
                                    keyboardType:
                                        TextInputType.numberWithOptions(
                                            decimal: true),
                                    decoration: InputDecoration(
                                      hintStyle: kNumberStyle,
                                      hintText: "0",
                                      fillColor: kActiveColor,
                                      enabledBorder: UnderlineInputBorder(
                                        borderSide: BorderSide(
                                          color: kActiveColor,
                                        ),
                                      ),
                                      focusedBorder: UnderlineInputBorder(
                                        borderSide: BorderSide(
                                          color: kActiveColor,
                                        ),
                                      ),
                                    ),
                                    fullwidth: false,
                                  ),
                                ),
                              ],
                            ),
                          ],
                        ),
                      ),
                    ),
                    Expanded(
                      child: DisplayCard(
                        cardChild: Column(
                          mainAxisAlignment: MainAxisAlignment.center,
                          crossAxisAlignment: CrossAxisAlignment.center,
                          children: <Widget>[
                            Text(
                              "SPLIT",
                              style: kLabelTextStyle,
                            ),
                            Text(
                              "$_split",
                              style: kNumberStyle,
                            ),
                            Row(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: <Widget>[
                                ChangingButton(
                                  onPressed: () {
                                    setState(() {
                                      if (_split > 1) {
                                        _split--;
                                      }
                                    });
                                  },
                                  icon: FontAwesomeIcons.minus,
                                ),
                                SizedBox(
                                  width: 10.0,
                                ),
                                ChangingButton(
                                  onPressed: () {
                                    setState(() {
                                      _split++;
                                    });
                                  },
                                  icon: FontAwesomeIcons.plus,
                                ),
                              ],
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
              Expanded(
                child: DisplayCard(
                  cardChild: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: <Widget>[
                      Text(
                        "TIP",
                        style: kLabelTextStyle,
                      ),
                      Column(
                        children: <Widget>[
                          Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: <Widget>[
                              Text(
                                _tipPercent.toString(),
                                style: kNumberStyle,
                              ),
                              Padding(
                                padding: EdgeInsets.only(left: 8.0),
                                child: Text(
                                  "%",
                                  style: kPrePostTextStyle,
                                ),
                              ),
                            ],
                          ),
                          SliderTheme(
                            data: SliderTheme.of(context).copyWith(
                              thumbColor: kActiveColor,
                              overlayColor: kInactiveColor,
                              thumbShape: RoundSliderThumbShape(
                                enabledThumbRadius: 15.0,
                              ),
                              overlayShape: RoundSliderOverlayShape(
                                overlayRadius: 30.0,
                              ),
                            ),
                            child: SizedBox(
                              width: 300.0,
                              child: Slider(
                                value: _tipPercent.toDouble(),
                                activeColor: kActiveColor,
                                inactiveColor: Colors.grey,
                                divisions: 20,
                                min: 0.0,
                                max: 100.0,
                                onChanged: (double newValue) {
                                  setState(() {
                                    _tipPercent = newValue.round();
                                  });
                                },
                              ),
                            ),
                          ),
                        ],
                      ),
                    ],
                  ),
                ),
              ),
              Expanded(
                child: DisplayCard(
                  cardChild: Center(
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: <Widget>[
                        Column(
                          children: <Widget>[
                            Text(
                              "TOTAL PER PERSON",
                              style: kLabelTextStyle,
                            ),
                            Row(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: <Widget>[
                                Padding(
                                  padding: const EdgeInsets.only(right: 8.0),
                                  child: Text(
                                    "₹",
                                    style: kPrePostTextStyle,
                                  ),
                                ),
                                Text(
                                  "${calculateTotalPerPerson(_billAmount, _tipPercent, _split)}",
                                  style: kNumberStyle,
                                ),
                              ],
                            ),
                          ],
                        ),
                        SizedBox(
                          height: 25.0,
                          width: 250.0,
                          child: Divider(
                            thickness: 1.0,
                            color: Colors.black,
                          ),
                        ),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            Column(
                              children: <Widget>[
                                Text(
                                  "BILL",
                                  style: kLabelTextStyle,
                                ),
                                Row(
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  children: <Widget>[
                                    Padding(
                                      padding:
                                          const EdgeInsets.only(right: 8.0),
                                      child: Text(
                                        "₹",
                                        style: kPrePostTextStyle,
                                      ),
                                    ),
                                    Text(
                                      "${calculateBill(_billAmount, _split)}",
                                      style: kPrePostTextStyle,
                                    ),
                                  ],
                                ),
                              ],
                            ),
                            SizedBox(
                              width: 50.0,
                            ),
                            Column(
                              children: <Widget>[
                                Text(
                                  "TIP",
                                  style: kLabelTextStyle,
                                ),
                                Row(
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  children: [
                                    Padding(
                                      padding:
                                          const EdgeInsets.only(right: 8.0),
                                      child: Text(
                                        "₹",
                                        style: kPrePostTextStyle,
                                      ),
                                    ),
                                    Text(
                                      "${calculateTip(_billAmount, _tipPercent, _split)}",
                                      style: kPrePostTextStyle,
                                    ),
                                  ],
                                ),
                              ],
                            ),
                          ],
                        ),
                      ],
                    ),
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }

  calculateBill(double billAmount, int split) {
    var bill = billAmount / split;

    return double.parse(bill.toStringAsFixed(2));
  }

  calculateTip(double billAmount, int tipPercent, int split) {
    var tip = (billAmount * tipPercent) / (100 * split);

    return double.parse(tip.toStringAsFixed(2));
  }

  calculateTotalPerPerson(double billAmount, int tipPercent, int split) {
    var totalPerPerson = (billAmount / split) + ((billAmount * tipPercent) / (100 * split));

    return double.parse(totalPerPerson.toStringAsFixed(2));
  }
}
