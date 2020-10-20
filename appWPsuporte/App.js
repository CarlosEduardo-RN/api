import React, { Component } from 'react';
import { View } from 'react-native';
import { contStyles } from './src/frontend/components/styles/index';


//IMPORTS DA PASTA SRC/FRONTEND/COMPONENTS/SCREENS 
//TELAS E BARRA DE NAVEGAÇAO
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**/import TabBar from './src/frontend/components/screens/TabBar';      /**/
/**/import NavBar from './src/frontend/components/screens/NavBar';      /**/
/**/import Dashboard from './src/frontend/components/screens/Dashboard';/**/
/**/import Chat from './src/frontend/components/screens/Chat';          /**/
/**/import Cadastro from './src/frontend/components/screens/Cadastro';  /**/
/**/import Chamados from './src/frontend/components/screens/Chamados';  /**/
/**/import Historico from './src/frontend/components/screens/Historico';/**/
/**/import Relatorio from './src/frontend/components/screens/Relatorio';/**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

export default class App extends Component {
  constructor(props){
    super(props);
    this.state = { tela: 'dash'}

    this._renderScene = this._renderScene.bind(this);
  }

  _renderScene(cena){
    this.setState({tela: cena})
  }

  render(){
    if(this.state.tela == 'dash'){
      return (
        <View style={contStyles.container}>
          <View style={contStyles.container}>
            <NavBar />
            <View style={contStyles.count}>
              <TabBar _renderScene={this._renderScene}/>
              <Dashboard />
            </View>
          </View>
        </View>
      );
    }
    if(this.state.tela == 'chat'){
      return (
        <View style={contStyles.container}>
          <View style={contStyles.container}>
            <NavBar />
            <View style={contStyles.count}>
              <TabBar _renderScene={this._renderScene}/>
              <Chat />
            </View>
          </View>
        </View>
      );
    }
    if(this.state.tela == 'chamado'){
      return (
        <View style={contStyles.container}>
          <View style={contStyles.container}>
            <NavBar />
            <View style={contStyles.count}>
              <TabBar _renderScene={this._renderScene}/>
              <Chamados />
            </View>
          </View>
        </View>
      );
    }
    if(this.state.tela == 'historico'){
      return (
        <View style={contStyles.container}>
          <View style={contStyles.container}>
            <NavBar />
            <View style={contStyles.count}>
              <TabBar _renderScene={this._renderScene}/>
              <Historico />
            </View>
          </View>
        </View>
      );
    }
    if(this.state.tela == 'cadastro'){
      return (
        <View style={contStyles.container}>
          <View style={contStyles.container}>
            <NavBar />
            <View style={contStyles.count}>
              <TabBar _renderScene={this._renderScene}/>
              <Cadastro />
            </View>
          </View>
        </View>
      );
    }
    if(this.state.tela == 'relatorio'){
      return (
        <View style={contStyles.container}>
          <View style={contStyles.container}>
            <NavBar />
            <View style={contStyles.count}>
              <TabBar _renderScene={this._renderScene}/>
              <Relatorio />
            </View>
          </View>
        </View>
      );
    }
  }
}


