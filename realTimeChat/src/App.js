import React, { Component } from 'react';
import {
  StyleSheet,
  View,
  Text
} from 'react-native';

import TabBar from './components/TabBar';
import Home from './screens/Home';
import Atendimentos from './screens/Atendimentos';



export default class App extends Component {

  constructor(props){
    super(props);
    this.state = {
      home: 0, atend: 0, rel: 0, chat: 0
    };
  }


  render(){
  return (
    <View style={styles.container}>
      <TabBar />
      <Home />
    </View>
  );
  }
};

const styles = StyleSheet.create({
 container: {
   height:'100%',
   width:'100%'
 }
});


