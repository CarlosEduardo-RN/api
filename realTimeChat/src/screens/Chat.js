import React from 'react';
import { Text, View } from 'react-native';

// import { Container } from './styles';

const Chat = () => {
  return (
      <View style={styles.container}>
          <Text>CHAT </Text>
      </View>
  );
}

const styles = StyleSheet.create({
    container:{
      height:'100%',
      width:'100%',
      backgroundColor:'#fff',
      padding: 10
    }
  })
  
export default Chat;