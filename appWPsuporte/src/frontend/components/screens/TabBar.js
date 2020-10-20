import React from 'react';
import { Image, View, Text, TouchableHighlight } from 'react-native';

import { tabStyles } from '../styles/index';

const chat = 'chat'
const cada = 'cadastro'
const dash = 'dash';
const cham = 'chamado';
const hist = 'historico';
const rela = 'relatorio';

const TabBar = props => {
    console.log(props._renderScene)
  return (
    <View style={tabStyles.tabBar}>
        <Image style={tabStyles.tabBarImg} resizeMode="contain" source={require('../../../frontend/img/logo.png')} />
        <View style={tabStyles.tabBarViewButtons}>
            <TouchableHighlight underlayColor="#fff" onPress={() => props._renderScene(dash)}>
                <Text style={tabStyles.tabBarTextButtons}>CENTRAL</Text>
            </TouchableHighlight>
        </View>
        <View style={tabStyles.tabBarViewButtons}>
            <TouchableHighlight underlayColor="#fff" onPress={() => props._renderScene(cham)}>
                <Text style={tabStyles.tabBarTextButtons}>CHAMADOS</Text>
            </TouchableHighlight>
        </View>
        <View style={tabStyles.tabBarViewButtons}>
            <TouchableHighlight underlayColor="#fff" onPress={() => props._renderScene(hist)}>
                <Text style={tabStyles.tabBarTextButtons}>HISTÓRICO</Text>
            </TouchableHighlight>
        </View>
        <View style={tabStyles.tabBarViewButtons}>
            <TouchableHighlight underlayColor="#fff" onPress={() => props._renderScene(cada)}>
                <Text style={tabStyles.tabBarTextButtons}>CADASTROS</Text>
            </TouchableHighlight>
        </View>
        <View style={tabStyles.tabBarViewButtons}>
            <TouchableHighlight underlayColor="#fff" onPress={() => props._renderScene(chat)}>
                <Text style={tabStyles.tabBarTextButtons}>CHAT</Text>
            </TouchableHighlight>
        </View>
        <View style={tabStyles.tabBarViewButtons}>
            <TouchableHighlight underlayColor="#fff" onPress={() => props._renderScene(rela)}>
                <Text style={tabStyles.tabBarTextButtons}>RELATÓRIOS</Text>
            </TouchableHighlight>
        </View>
    </View>
  )
}

export default TabBar;